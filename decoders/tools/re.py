#!/usr/bin/env python3
"""re.py - one lookup tool for both Freedom Fighters builds (PC x86 exe + GameCube PPC ELF).

  python3 -I decoders/tools/re.py fn <name|addr> [--build pc|gc] [--no-dis] [--lines N]
  python3 -I decoders/tools/re.py xrefs <addr|string> [--build pc|gc]
  python3 -I decoders/tools/re.py strings <regex> [--build pc|gc] [--all]
  python3 -I decoders/tools/re.py sym <regex> [--limit N]
  python3 -I decoders/tools/re.py map <pc_addr|gc_name|gc_addr>

Address forms: PC = 0x4edb80, 4edb80, FUN_004edb80; GC = 80216e8c (8 hex digits, 8xxxxxxx).
Anything else is a GC symbol: mangled (InstallCollisionBuffer__14ZCollisionBasePci), demangled
(ZCollisionBase::InstallCollisionBuffer) or a regex over either.
Paths: FF_RE_ROOT (default ~/freedom-fighters-re, fallback the current directory),
name map FF_NAMEMAP (default decoders/gc_pc_namemap.tsv). See README.md.
"""
# This file is called re.py; make sure 'import re' below gets the stdlib module even when the
# script is run without -I (the script's own directory is sys.path[0] then).
import sys as _sys, os as _os
_here = _os.path.dirname(_os.path.abspath(__file__))
_sys.path[:] = [p for p in _sys.path if _os.path.abspath(p or '.') != _here]
_sys.modules.pop('re', None) if getattr(_sys.modules.get('re'), '__file__', '') == _os.path.abspath(__file__) else None
import re  # noqa: E402  (stdlib)
import argparse, collections, struct  # noqa: E402
_sys.path.append(_here)
import ffre  # noqa: E402

_pc = _gc = None
_nm = None


def PC():
    global _pc
    if _pc is None:
        _pc = ffre.PC()
    return _pc


def GC():
    global _gc
    if _gc is None:
        _gc = ffre.GC()
    return _gc


def NM():
    """(by_gc_addr, by_pc_addr -> [rows])"""
    global _nm
    if _nm is None:
        rows = ffre.load_namemap()
        bg = {r['gc_addr_i']: r for r in rows}
        bp = collections.defaultdict(list)
        for r in rows:
            bp[r['pc_addr_i']].append(r)
        _nm = (bg, bp)
    return _nm


CONF_ORDER = {'high': 0, 'medium': 1, 'low': 2}


def pc_label(a):
    pc = PC()
    f = pc.funcs.get(a)
    base = f['name'] if f else ('0x%06x' % a)
    rows = NM()[1].get(a)
    if rows:
        rows = sorted(rows, key=lambda r: CONF_ORDER.get(r['confidence'], 3))
        r = rows[0]
        more = ' +%d' % (len(rows) - 1) if len(rows) > 1 else ''
        return '%s = %s [%s%s]' % (base, ffre.short_demangled(r['gc_demangled']), r['confidence'], more)
    return base


def gc_label(a, demangle=True):
    gc = GC()
    f = gc.funcs.get(a)
    nm = f['name'] if f else gc.symat(a)
    return ffre.demangle(nm) if demangle else nm


# ----------------------------------------------------------------------------- resolution
def parse_target(s, build=None):
    """-> (build, addr) or (build, [candidates])"""
    t = s.strip()
    m = re.fullmatch(r'(?:FUN_|LAB_|sub_)?(?:0x)?([0-9a-fA-F]{5,8})', t)
    if m and (build in (None, 'pc', 'gc')):
        v = int(m.group(1), 16)
        if build == 'gc' or (build is None and len(m.group(1)) == 8 and v >= 0x80000000 and not t.lower().startswith(('0x', 'fun_'))):
            return 'gc', v
        if build == 'pc' or v < 0x1000000:
            return 'pc', v
    # GC symbol
    gc = GC()
    if t in gc.byname:
        fs = [a for a in gc.byname[t] if a in gc.funcs] or gc.byname[t]
        return 'gc', fs[0] if len(fs) == 1 else fs
    # demangled exact (without args) or regex
    exact, rx = [], []
    try:
        r = re.compile(t)
    except re.error:
        r = re.compile(re.escape(t))
    for a, f in gc.funcs.items():
        dm = ffre.demangle(f['name'])
        if ffre.short_demangled(dm) == t or dm == t:
            exact.append(a)
        elif r.search(f['name']) or r.search(dm):
            rx.append(a)
    c = exact or rx
    if len(c) == 1:
        return 'gc', c[0]
    return 'gc', sorted(c)


def containing(build, a):
    if build == 'pc':
        return PC().fn_of(a)
    return GC().fn_of(a)


# ----------------------------------------------------------------------------- fn
def cmd_fn(args):
    build, a = parse_target(args.target, args.build)
    if isinstance(a, list):
        if not a:
            print('no match for %r' % args.target)
            return 1
        print('%d GC functions match %r:' % (len(a), args.target))
        for x in a[:60]:
            print('  %08x  %s' % (x, gc_label(x)))
        if len(a) > 60:
            print('  ...')
        return 0
    e = containing(build, a)
    if e is None:
        print('%s %x is not inside a known function' % (build.upper(), a))
        return 1
    if e != a:
        print('(%x is inside function %x)' % (a, e))
    (show_pc if build == 'pc' else show_gc)(e, args)
    return 0


def vtable_slots(b, e):
    """['Class[slot]', ...] for every vtable slot (MSVC RTTI / GCC _vt symbols) pointing at e."""
    if not hasattr(b, '_slot_index'):
        idx = collections.defaultdict(list)
        for cls, (va, slots) in b.vtables().items():
            for i, t in enumerate(slots):
                if t:
                    idx[t].append('%s[%d]' % (cls, i))
        b._slot_index = idx
    return b._slot_index.get(e, [])


def other_build_pc(e):
    rows = NM()[1].get(e, [])
    out = []
    for r in sorted(rows, key=lambda r: CONF_ORDER.get(r['confidence'], 3)):
        out.append('GC %s %s  [%s] %s' % (r['gc_addr'], r['gc_demangled'], r['confidence'], r['evidence']))
    return out


def show_pc(e, args):
    pc = PC()
    f = pc.funcs[e]
    print('PC 0x%06x  %s  size %d  ranges %s%s' % (e, f['name'], f['size'],
          ' '.join('%x-%x' % (lo, hi) for lo, hi in f['ranges']), '  (thunk)' if f.get('thunk') else ''))
    m = other_build_pc(e)
    if m:
        for x in m:
            print('  match: ' + x)
    elif ffre.load_namemap() == []:
        print('  match: (no name map at %s)' % ffre.NAMEMAP)
    else:
        print('  match: none in name map')
    cl = pc.callers(e)
    print('callers (%d):' % len(cl))
    for c in cl[:args.lines]:
        print('  0x%06x  %s' % (c, pc_label(c)))
    vs = vtable_slots(pc, e)
    if vs:
        print('vtable slots (%d): %s%s' % (len(vs), ', '.join(vs[:12]), ' ...' if len(vs) > 12 else ''))
    ce = pc.callees(e)
    print('callees (%d):' % len(ce))
    for c in ce[:args.lines]:
        print('  0x%06x  %s' % (c, pc_label(c)))
    ss = pc.strings_of(e)
    print('strings (%d):' % len(ss))
    for site, t, s in ss[:args.lines]:
        print('  0x%06x -> 0x%06x  %r' % (site, t, s[:120]))
    fl = pc.floats_of(e)
    if fl:
        print('float literals: %s' % ', '.join('%g' % v for v in sorted(set(fl))))
    if args.no_dis:
        return
    strs = {t: s for _, t, s in ss}
    print('disassembly:')
    n = 0
    for addr, mn, op in pc.disasm(e):
        c = ''
        for h in re.findall(r'0x[0-9a-f]{6,}', op):
            v = int(h, 16)
            if v in pc.funcs and v != e:
                c = '  ; ' + pc_label(v)
            elif v in strs:
                c = '  ; %r' % strs[v][:60]
        print('  %06x  %-7s %s%s' % (addr, mn, op, c))
        n += 1
        if args.max_ins and n >= args.max_ins:
            print('  ... (truncated, --max-ins 0 for all)')
            break


def show_gc(e, args):
    gc = GC()
    f = gc.funcs[e]
    print('GC %08x  %s' % (e, ffre.demangle(f['name'])))
    print('  mangled: %s  size %d  unit %s%s' % (f['name'], f['size'], gc.cu_name(e), '  (local)' if f.get('local') else ''))
    r = NM()[0].get(e)
    if r:
        print('  match: PC %s %s  [%s] %s' % (r['pc_addr'], PC().funcs.get(r['pc_addr_i'], {}).get('name', ''), r['confidence'], r['evidence']))
    elif ffre.load_namemap() == []:
        print('  match: (no name map at %s)' % ffre.NAMEMAP)
    else:
        print('  match: none in name map')
    cl = gc.callers(e)
    print('callers (%d):' % len(cl))
    for c in cl[:args.lines]:
        print('  %08x  %s' % (c, gc_label(c)))
    vs = vtable_slots(gc, e)
    if vs:
        print('vtable slots (%d): %s%s' % (len(vs), ', '.join(vs[:12]), ' ...' if len(vs) > 12 else ''))
    ce = gc.callees(e)
    print('callees (%d):' % len(ce))
    for c in ce[:args.lines]:
        print('  %08x  %s' % (c, gc_label(c)))
    ss = gc.strings_of(e)
    print('strings (%d):' % len(ss))
    for site, t, s in ss[:args.lines]:
        print('  %08x -> %08x  %r' % (site, t, s[:120]))
    fl = gc.floats_of(e)
    if fl:
        print('float literals: %s' % ', '.join('%g' % v for v in sorted(set(fl))))
    if args.no_dis:
        return
    refs = {site: (t, k) for site, t, k in gc.an['refs'].get(e, [])}
    strs = {t: s for _, t, s in ss}
    print('disassembly:')
    n = 0
    for addr, mn, op in gc.disasm(e):
        c = ''
        if mn.startswith('b') and re.search(r'0x[0-9a-f]+$', op):
            t = int(re.search(r'0x[0-9a-f]+$', op).group(), 16)
            if not (e <= t < e + f['size']):
                c = '  ; ' + gc_label(t)
        elif addr in refs:
            t, k = refs[addr]
            if t in strs:
                c = '  ; %08x %r' % (t, strs[t][:60])
            else:
                c = '  ; %08x %s' % (t, gc.symat(t))
        print('  %08x  %-8s %s%s' % (addr, mn, op, c))
        n += 1
        if args.max_ins and n >= args.max_ins:
            print('  ... (truncated, --max-ins 0 for all)')
            break


# ----------------------------------------------------------------------------- xrefs
def _find_string(b, s):
    out = []
    for addr, t in b.all_strings(3):
        if t == s:
            out.append(addr)
    return out


def cmd_xrefs(args):
    t = args.target
    m = re.fullmatch(r'(?:FUN_|0x)?([0-9a-fA-F]{5,8})', t)
    builds = [args.build] if args.build else None
    if m:
        bld, a = parse_target(t, args.build)
        targets = [(bld, a)]
    else:
        targets = []
        for bld in (builds or ['pc', 'gc']):
            b = PC() if bld == 'pc' else GC()
            for a in _find_string(b, t):
                targets.append((bld, a))
        if not targets:
            print('string %r not found (exact match; use "strings" for regex search)' % t)
            return 1
    for bld, a in targets:
        b = PC() if bld == 'pc' else GC()
        fmt = b.fmt
        s = b.cstr(a)
        print('%s %s%s' % (bld.upper(), fmt(a), ('  %r' % s) if s else ''))
        # code calls
        if a in b.funcs:
            cl = b.callers(a)
            print('  called from %d functions:' % len(cl))
            for c in cl[:args.lines]:
                print('    %s  %s' % (fmt(c), pc_label(c) if bld == 'pc' else gc_label(c)))
        refs = b.data_xrefs(a)
        print('  %d pointer references:' % len(refs))
        for site, fn in refs[:args.lines]:
            if fn is not None:
                print('    %s in %s  %s' % (fmt(site), fmt(fn), pc_label(fn) if bld == 'pc' else gc_label(fn)))
            else:
                print('    %s (data, %s)' % (fmt(site), b.section_of(site)))
    return 0


# ----------------------------------------------------------------------------- strings
def cmd_strings(args):
    try:
        r = re.compile(args.regex)
    except re.error as ex:
        print('bad regex: %s' % ex)
        return 1
    for bld in ([args.build] if args.build else ['pc', 'gc']):
        b = PC() if bld == 'pc' else GC()
        # referencing functions per string address
        refd = collections.defaultdict(set)
        for e, rf in b.an['refs'].items():
            for site, t, k in rf:
                refd[t].add(e)
        hits = [(a, s) for a, s in b.all_strings(3) if r.search(s)]
        if not args.all:
            hits = [(a, s) for a, s in hits if refd.get(a)]
        print('== %s: %d strings%s' % (bld.upper(), len(hits), '' if args.all else ' (referenced from code; --all for every string)'))
        for a, s in hits[:args.limit]:
            fns = sorted(refd.get(a, ()))
            lab = ', '.join((pc_label(f) if bld == 'pc' else '%08x %s' % (f, ffre.short_demangled(gc_label(f)))) for f in fns[:3])
            if len(fns) > 3:
                lab += ', +%d' % (len(fns) - 3)
            print('  %s  %-60r  %s' % (b.fmt(a), s[:60], lab))
        if len(hits) > args.limit:
            print('  ... %d more (--limit)' % (len(hits) - args.limit))
    return 0


# ----------------------------------------------------------------------------- sym
def cmd_sym(args):
    gc = GC()
    try:
        r = re.compile(args.regex)
    except re.error as ex:
        print('bad regex: %s' % ex)
        return 1
    bg = NM()[0]
    n = 0
    seen = set()
    for a, name, size, typ in gc.syms:
        if (a, name) in seen:
            continue
        seen.add((a, name))
        dm = ffre.demangle(name)
        if not (r.search(name) or r.search(dm)):
            continue
        n += 1
        if n > args.limit:
            continue
        kind = {1: 'obj ', 2: 'func', 0: 'nt  ', 4: 'file'}.get(typ, '?   ')
        mt = ''
        if a in bg:
            mt = '  -> PC %s [%s]' % (bg[a]['pc_addr'], bg[a]['confidence'])
        print('%08x %s %6d  %s%s' % (a, kind, size, dm, mt))
        if dm != name:
            print('                        %s' % name)
    if n > args.limit:
        print('... %d more (--limit)' % (n - args.limit))
    print('%d symbols' % n)
    return 0


# ----------------------------------------------------------------------------- map
def cmd_map(args):
    rows = ffre.load_namemap()
    if not rows:
        print('no name map at %s (run namemap.py)' % ffre.NAMEMAP)
        return 1
    bg, bp = NM()
    t = args.target
    m = re.fullmatch(r'(?:FUN_|0x)?([0-9a-fA-F]{5,8})', t)
    found = []
    if m:
        v = int(m.group(1), 16)
        if v >= 0x80000000:
            if v in bg:
                found.append(bg[v])
        else:
            found += bp.get(v, [])
            if not found:
                e = PC().fn_of(v)
                if e is not None and e != v:
                    print('(0x%x is inside 0x%06x)' % (v, e))
                    found += bp.get(e, [])
    else:
        try:
            r = re.compile(t)
        except re.error:
            r = re.compile(re.escape(t))
        for row in rows:
            if row['gc_name'] == t or ffre.short_demangled(row['gc_demangled']) == t:
                found.insert(0, row)
            elif r.search(row['gc_name']) or r.search(row['gc_demangled']):
                found.append(row)
    if not found:
        print('no mapping for %r' % t)
        return 1
    for row in found[:args.limit]:
        print('PC %s  <->  GC %s %s\n    [%s] %s' % (row['pc_addr'], row['gc_addr'], row['gc_demangled'],
                                                  row['confidence'], row['evidence']))
    if len(found) > args.limit:
        print('... %d more (--limit)' % (len(found) - args.limit))
    return 0


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sp = ap.add_subparsers(dest='cmd')
    p = sp.add_parser('fn', help='disassembly, callers, callees, strings, matched function')
    p.add_argument('target')
    p.add_argument('--build', choices=['pc', 'gc'])
    p.add_argument('--no-dis', action='store_true', help='skip the disassembly')
    p.add_argument('--max-ins', type=int, default=400, help='disassembly line limit (0 = all)')
    p.add_argument('--lines', type=int, default=40, help='max callers/callees/strings listed')
    p = sp.add_parser('xrefs', help='references to an address or an exact string')
    p.add_argument('target')
    p.add_argument('--build', choices=['pc', 'gc'])
    p.add_argument('--lines', type=int, default=60)
    p = sp.add_parser('strings', help='search strings (regex) in both builds')
    p.add_argument('regex')
    p.add_argument('--build', choices=['pc', 'gc'])
    p.add_argument('--all', action='store_true', help='include strings no code references')
    p.add_argument('--limit', type=int, default=50)
    p = sp.add_parser('sym', help='search GC symbols (regex over mangled and demangled)')
    p.add_argument('regex')
    p.add_argument('--limit', type=int, default=100)
    p = sp.add_parser('map', help='name map lookup by PC address, GC address or GC name')
    p.add_argument('target')
    p.add_argument('--limit', type=int, default=20)
    a = ap.parse_args(argv)
    if not a.cmd:
        ap.print_help()
        return 1
    return {'fn': cmd_fn, 'xrefs': cmd_xrefs, 'strings': cmd_strings, 'sym': cmd_sym, 'map': cmd_map}[a.cmd](a)


if __name__ == '__main__':
    try:
        _sys.exit(main())
    except BrokenPipeError:
        pass

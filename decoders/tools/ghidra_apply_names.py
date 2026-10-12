# Apply GameCube symbol names to the PC Freedom Fighters Ghidra project.
#
# Reads decoders/gc_pc_namemap.tsv (built by decoders/tools/namemap.py) and renames PC functions
# after their matched GameCube function. Default: high + medium rows only.
#
#   GUI:      Script Manager -> run; you are asked for the TSV file (and confidence level).
#   Headless: analyzeHeadless <projdir> <projname> -process Freedom.Exe.orig -noanalysis \
#               -scriptPath <repo>/decoders/tools -postScript ghidra_apply_names.py \
#               "tsv=<repo>/decoders/gc_pc_namemap.tsv" "min=medium" "mode=namespace" "dry=0"
#
# Arguments (key=value, all optional):
#   tsv=PATH      name map (default: ../gc_pc_namemap.tsv next to this script)
#   min=LEVEL     high | medium | low  (default medium)
#   mode=MODE     namespace: GC::Class::method   (default; root namespace from root=)
#                 flat:      gc_Class__method
#   root=NAME     namespace root / flat prefix stem (default GC)
#   force=1       also rename functions that already have a user-given (non-default) name
#   dry=1         print what would change, change nothing
#
# Safe to re-run: a function is renamed only when its name is still a Ghidra default
# (FUN_xxxxxxxx, thunk_FUN_...) or was set by this script before (it lives under the root
# namespace / carries the flat prefix). The plate comment line starting with [gc_pc_namemap]
# is replaced, other comment text is kept. PC functions that several GC functions map to
# (identical-code folding) are not renamed; they only get the comment listing the candidates.
#
# @category FreedomFighters
# @runtime PyGhidra

import os
import re

CONF_RANK = {'high': 0, 'medium': 1, 'low': 2}
MARK = '[gc_pc_namemap]'


# ---------------------------------------------------------------- pure python (testable)
def parse_tsv(path):
    rows = []
    f = open(path)
    try:
        hdr = None
        for line in f:
            line = line.rstrip('\r\n')
            if not line or line.startswith('#'):
                continue
            p = line.split('\t')
            if hdr is None:
                hdr = p
                continue
            rows.append(dict(zip(hdr, p)))
    finally:
        f.close()
    return rows


def split_demangled(dm):
    """'A::B<x, y>::m(int) const' -> (['A', 'B<x,y>'], 'm')"""
    i = dm.find('(')
    base = dm[:i] if i > 0 else dm
    parts, depth, cur = [], 0, ''
    k = 0
    while k < len(base):
        c = base[k]
        if c == '<':
            depth += 1
        elif c == '>':
            depth -= 1
        if depth == 0 and base.startswith('::', k):
            parts.append(cur)
            cur = ''
            k += 2
            continue
        cur += c
        k += 1
    parts.append(cur)
    return parts[:-1], parts[-1]


def clean(s):
    s = s.replace(', ', ',').replace(' ', '_')
    s = re.sub(r'[^A-Za-z0-9_:~<>,.\[\]=!+\-*/&|^%$@]', '_', s)
    s = s.replace('*', 'P').replace('&', 'R')
    return s or '_'


def build_plan(rows, min_conf='medium', mode='namespace', root='GC'):
    """-> list of (pc_addr:int, namespace_path or None, name, comment, rename:bool)"""
    lim = CONF_RANK[min_conf]
    by_pc = {}
    for r in rows:
        try:
            pa = int(r['pc_addr'], 16)
        except (KeyError, ValueError):
            continue
        by_pc.setdefault(pa, []).append(r)
    plan = []
    for pa in sorted(by_pc):
        cands = [r for r in by_pc[pa] if CONF_RANK.get(r.get('confidence'), 9) <= lim]
        if not cands:
            continue
        cands.sort(key=lambda r: CONF_RANK.get(r['confidence'], 9))
        lines = ['%s GC %s %s [%s] %s' % (MARK, r['gc_addr'], r['gc_demangled'], r['confidence'], r['evidence'])
                 for r in cands]
        distinct = set(r['gc_demangled'] for r in cands)
        if len(distinct) > 1:
            plan.append((pa, None, None, '\n'.join([MARK + ' %d GameCube functions map here (identical-code folding?); not renamed' % len(distinct)] + lines), False))
            continue
        r = cands[0]
        classes, meth = split_demangled(r['gc_demangled'])
        if mode == 'flat':
            name = clean('%s_%s' % (root.lower(), '__'.join(classes + [meth])))
            plan.append((pa, None, name, '\n'.join(lines), True))
        else:
            ns = '::'.join([root] + [clean(c) for c in classes])
            plan.append((pa, ns, clean(meth), '\n'.join(lines), True))
    return plan


def merge_comment(old, new):
    keep = [l for l in (old or '').split('\n') if l and not l.startswith(MARK)]
    return '\n'.join(keep + [new]) if keep else new


# ---------------------------------------------------------------- Ghidra side
def _args():
    out = {}
    try:
        for a in getScriptArgs():  # noqa: F821 (Ghidra builtin)
            if '=' in a:
                k, v = a.split('=', 1)
                out[k.strip()] = v.strip()
    except NameError:
        pass
    return out


def _is_default_name(n):
    return re.match(r'^(thunk_)?(FUN|SUB|LAB|UNK)_[0-9a-fA-F]+$', n) is not None


def run_in_ghidra():
    from ghidra.program.model.symbol import SourceType
    from ghidra.app.util import NamespaceUtils
    from ghidra.util.exception import DuplicateNameException

    a = _args()
    here = None
    try:
        here = os.path.dirname(getSourceFile().getAbsolutePath())  # noqa: F821
    except Exception:
        pass
    tsv = a.get('tsv')
    if not tsv and here:
        cand = os.path.normpath(os.path.join(here, '..', 'gc_pc_namemap.tsv'))
        if os.path.exists(cand):
            tsv = cand
    if not tsv and not isRunningHeadless():  # noqa: F821
        tsv = askFile('gc_pc_namemap.tsv', 'Use').getAbsolutePath()  # noqa: F821
    if not tsv:
        printerr('no name map: pass tsv=PATH')  # noqa: F821
        return
    min_conf = a.get('min')
    if not min_conf and not isRunningHeadless():  # noqa: F821
        min_conf = askChoice('Name map', 'Minimum confidence', ['high', 'medium', 'low'], 'medium')  # noqa: F821
    min_conf = min_conf or 'medium'
    mode = a.get('mode', 'namespace')
    root = a.get('root', 'GC')
    force = a.get('force', '0') == '1'
    dry = a.get('dry', '0') == '1'

    prog = currentProgram  # noqa: F821
    fm = prog.getFunctionManager()
    rows = parse_tsv(tsv)
    plan = build_plan(rows, min_conf, mode, root)
    stats = {'renamed': 0, 'same': 0, 'kept_user_name': 0, 'icf_comment_only': 0, 'no_function': 0, 'created': 0}
    flat_prefix = root.lower() + '_'
    for pa, ns, name, comment, rename in plan:
        if monitor.isCancelled():  # noqa: F821
            break
        addr = toAddr(pa)  # noqa: F821
        f = fm.getFunctionAt(addr)
        if f is None:
            if dry:
                stats['no_function'] += 1
                continue
            f = createFunction(addr, None)  # noqa: F821
            if f is None:
                stats['no_function'] += 1
                continue
            stats['created'] += 1
        if not dry:
            f.setComment(merge_comment(f.getComment(), comment))
        if not rename:
            stats['icf_comment_only'] += 1
            continue
        cur = f.getName()
        cur_ns = f.getParentNamespace()
        cur_full = f.getName(True)
        ours = cur_full.startswith(root + '::') or cur.startswith(flat_prefix)
        if not (_is_default_name(cur) or ours or force):
            stats['kept_user_name'] += 1
            continue
        target_full = (ns + '::' + name) if ns else name
        if cur_full == target_full or cur_full.startswith(target_full + '_'):
            stats['same'] += 1
            continue
        if dry:
            println('would rename %s %s -> %s' % (addr, cur_full, target_full))  # noqa: F821
            stats['renamed'] += 1
            continue
        try:
            if ns:
                nso = NamespaceUtils.createNamespaceHierarchy(ns, None, prog, SourceType.IMPORTED)
                f.setParentNamespace(nso)
            try:
                f.setName(name, SourceType.IMPORTED)
            except DuplicateNameException:
                f.setName('%s_%x' % (name, pa), SourceType.IMPORTED)
            stats['renamed'] += 1
        except Exception as ex:  # keep going
            printerr('failed %s -> %s: %s' % (addr, target_full, ex))  # noqa: F821
    println('gc_pc_namemap: %s (min=%s, mode=%s, rows=%d, planned=%d)%s' % (  # noqa: F821
        ', '.join('%s %d' % kv for kv in sorted(stats.items())), min_conf, mode, len(rows), len(plan),
        ' DRY RUN' if dry else ''))


try:
    currentProgram  # noqa: F821
    _IN_GHIDRA = True
except NameError:
    _IN_GHIDRA = False

if _IN_GHIDRA:
    run_in_ghidra()
elif __name__ == '__main__':
    # outside Ghidra: print the plan (handy for checking the TSV)
    import sys
    path = sys.argv[1] if len(sys.argv) > 1 else os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', 'gc_pc_namemap.tsv')
    lvl = sys.argv[2] if len(sys.argv) > 2 else 'medium'
    plan = build_plan(parse_tsv(path), lvl)
    n = 0
    for pa, ns, name, comment, rename in plan:
        if n < 15:
            print('0x%06x  %s' % (pa, ('%s::%s' % (ns, name)) if rename else '(comment only: ' + comment.split('\n')[0] + ')'))
        n += 1
    print('%d PC functions planned (%d renames, %d comment-only) at min=%s' % (
        len(plan), sum(1 for p in plan if p[4]), sum(1 for p in plan if not p[4]), lvl))

"""ffre - shared loader/analysis library for the Freedom Fighters RE tools.

Used by re.py (lookup CLI) and namemap.py (GameCube -> PC name matcher).
Dependencies: Python 3 stdlib + capstone + pefile.

Layout (FF_RE_ROOT, default ~/freedom-fighters-re, fallback the
current directory):
    bin/Freedom.Exe.orig                          PC exe (x86, MSVC, has .reloc)
    out/functions.jsonl                           Ghidra function list (entry + ranges)
    samples/gamecube/files/startup_release.elf    GC ELF (PPC BE, GCC 2.x names, .symtab)
Name map: FF_NAMEMAP, default <this dir>/../gc_pc_namemap.tsv
Cache:    FF_RE_CACHE, default ~/.cache/ff-re  (pickles; delete to rebuild)
"""
import os, sys, re, struct, bisect, json, pickle, hashlib

HERE = os.path.dirname(os.path.abspath(__file__))
FALLBACK_ROOT = os.getcwd()
CACHE_VERSION = 5


def find_root():
    cands = []
    if os.environ.get('FF_RE_ROOT'):
        cands.append(os.path.expanduser(os.environ['FF_RE_ROOT']))
    cands += [os.path.expanduser('~/freedom-fighters-re'), FALLBACK_ROOT]
    for c in cands:
        if os.path.exists(os.path.join(c, 'bin', 'Freedom.Exe.orig')) or \
           os.path.exists(os.path.join(c, 'samples', 'gamecube', 'files', 'startup_release.elf')):
            return c
    return cands[0]


ROOT = find_root()
PC_EXE = os.path.join(ROOT, 'bin', 'Freedom.Exe.orig')
PC_FUNCS = os.path.join(ROOT, 'out', 'functions.jsonl')
GC_ELF = os.path.join(ROOT, 'samples', 'gamecube', 'files', 'startup_release.elf')
NAMEMAP = os.environ.get('FF_NAMEMAP') or os.path.normpath(os.path.join(HERE, '..', 'gc_pc_namemap.tsv'))
CACHE_DIR = os.path.expanduser(os.environ.get('FF_RE_CACHE', '~/.cache/ff-re'))


def _cached(tag, paths, builder):
    key = [CACHE_VERSION, tag]
    for p in paths:
        st = os.stat(p)
        key += [os.path.abspath(p), st.st_size, int(st.st_mtime)]
    h = hashlib.sha1(repr(key).encode()).hexdigest()[:16]
    fn = os.path.join(CACHE_DIR, '%s-%s.pkl' % (tag, h))
    try:
        with open(fn, 'rb') as f:
            return pickle.load(f)
    except Exception:
        pass
    obj = builder()
    try:
        os.makedirs(CACHE_DIR, exist_ok=True)
        with open(fn + '.tmp', 'wb') as f:
            pickle.dump(obj, f, protocol=4)
        os.replace(fn + '.tmp', fn)
    except Exception:
        pass
    return obj


# ---------------------------------------------------------------------------
# GCC 2.x demangler (display quality, not a complete cplus-dem clone)
# ---------------------------------------------------------------------------
_OPS = {
    'nw': 'operator new', 'dl': 'operator delete', 'vn': 'operator new[]', 'vd': 'operator delete[]',
    'as': 'operator=', 'eq': 'operator==', 'ne': 'operator!=', 'lt': 'operator<', 'gt': 'operator>',
    'le': 'operator<=', 'ge': 'operator>=', 'pl': 'operator+', 'mi': 'operator-', 'ml': 'operator*',
    'dv': 'operator/', 'md': 'operator%', 'apl': 'operator+=', 'ami': 'operator-=', 'aml': 'operator*=',
    'adv': 'operator/=', 'amd': 'operator%=', 'vc': 'operator[]', 'cl': 'operator()', 'rf': 'operator->',
    'nt': 'operator!', 'aa': 'operator&&', 'oo': 'operator||', 'ad': 'operator&', 'or': 'operator|',
    'er': 'operator^', 'co': 'operator~', 'ls': 'operator<<', 'rs': 'operator>>', 'als': 'operator<<=',
    'ars': 'operator>>=', 'aad': 'operator&=', 'aor': 'operator|=', 'aer': 'operator^=', 'pp': 'operator++',
    'mm': 'operator--', 'cm': 'operator,', 'rm': 'operator->*',
}
_BUILTIN = {'v': 'void', 'i': 'int', 'c': 'char', 's': 'short', 'l': 'long', 'x': 'long long',
            'f': 'float', 'd': 'double', 'r': 'long double', 'b': 'bool', 'w': 'wchar_t', 'e': '...'}


class _DM:
    def __init__(self, s):
        self.s = s
        self.i = 0
        self.types = []
        self.tbias = 1

    def peek(self):
        return self.s[self.i] if self.i < len(self.s) else ''

    def num(self):
        j = self.i
        while self.i < len(self.s) and self.s[self.i].isdigit():
            self.i += 1
        if j == self.i:
            raise ValueError('num')
        return int(self.s[j:self.i])

    def qnum(self):  # Q2 or Q_12_
        if self.peek() == '_':
            self.i += 1
            n = self.num()
            if self.peek() == '_':
                self.i += 1
            return n
        n = int(self.s[self.i]); self.i += 1
        return n

    def count(self):
        """GCC2 get_count: one digit, or several digits terminated by '_'."""
        m = re.match(r'(\d+)_', self.s[self.i:])
        if m and len(m.group(1)) > 1:
            self.i += len(m.group(0))
            return int(m.group(1))
        if not self.peek().isdigit():
            raise ValueError('count')
        self.i += 1
        return int(self.s[self.i - 1])

    def ident(self):
        n = self.num()
        r = self.s[self.i:self.i + n]
        if len(r) != n:
            raise ValueError('ident')
        self.i += n
        return r

    def template(self):
        name = self.ident()
        n = self.num()
        args = []
        for _ in range(n):
            if self.peek() == 'Z':
                self.i += 1
                args.append(self.type())
            else:  # non-type parameter: type then value
                self.type()
                neg = ''
                if self.peek() == 'm':
                    self.i += 1; neg = '-'
                if self.peek().isdigit():
                    args.append(neg + str(self.num()))
                else:
                    args.append('?')
        return '%s<%s>' % (name, ', '.join(args))

    def classname(self):
        c = self.peek()
        if c == 'Q':
            self.i += 1
            n = self.qnum()
            return '::'.join(self.classname() for _ in range(n))
        if c == 't':
            self.i += 1
            return self.template()
        if c == 'G':
            self.i += 1
            return self.classname()
        return self.ident()

    def type(self):
        pre = []
        while True:
            c = self.peek()
            if c == 'C': pre.append('const'); self.i += 1
            elif c == 'V': pre.append('volatile'); self.i += 1
            elif c == 'U': pre.append('unsigned'); self.i += 1
            elif c == 'S': pre.append('signed'); self.i += 1
            else: break
        c = self.peek()
        if c == 'P':
            self.i += 1
            t = self.type()
            r = t + '*'
        elif c == 'R':
            self.i += 1
            r = self.type() + '&'
        elif c == 'A':
            self.i += 1
            n = self.num() if self.peek().isdigit() else ''
            if self.peek() == '_':
                self.i += 1
            r = '%s[%s]' % (self.type(), n)
        elif c == 'F':
            self.i += 1
            args = self.arglist(stop='_')
            if self.peek() == '_':
                self.i += 1
            ret = self.type()
            r = '%s (*)(%s)' % (ret, args)
        elif c == 'M':
            self.i += 1
            cls = self.classname()
            while self.peek() in ('C', 'V'):
                self.i += 1
            if self.peek() == 'F':
                self.i += 1
                args = self.arglist(stop='_')
                if self.peek() == '_':
                    self.i += 1
                ret = self.type()
                r = '%s (%s::*)(%s)' % (ret, cls, args)
            else:
                r = '%s %s::*' % (self.type(), cls)
        elif c and c in _BUILTIN:
            self.i += 1
            r = _BUILTIN[c]
        elif c and (c.isdigit() or c in 'QtG'):
            r = self.classname()
        elif c == 'X' and getattr(self, 'targs', None) is not None:
            k = int(self.s[self.i + 1])
            self.i += 3          # X<index><level>
            r = self.targs[k] if k < len(self.targs) else 'T%d' % k
        else:
            raise ValueError('type %r at %d' % (c, self.i))
        if pre:
            if r.endswith('*') or r.endswith('&'):
                # const applies to the pointee in GCC2's prefix notation (PCc = const char*)
                r = ' '.join(pre) + ' ' + r
            else:
                r = ' '.join(pre) + ' ' + r
        return r

    def arglist(self, stop=''):
        out = []
        while self.i < len(self.s) and self.peek() != stop:
            c = self.peek()
            if c == 'T':
                self.i += 1
                n = self.count()
                t = self.types[n - self.tbias] if 0 <= n - self.tbias < len(self.types) else '?'
                out.append(t); self.types.append(t)
            elif c == 'N':
                self.i += 1
                cnt = self.count()
                n = self.count()
                t = self.types[n - self.tbias] if 0 <= n - self.tbias < len(self.types) else '?'
                for _ in range(cnt):
                    out.append(t); self.types.append(t)
            else:
                t = self.type()
                out.append(t); self.types.append(t)
        return ', '.join(x for x in out if x != 'void' or len(out) > 1) if out != ['void'] else 'void'


def demangle(name):
    """GCC 2.x demangle; returns the input unchanged when it cannot parse it."""
    try:
        r = _demangle(name)
        return r if r else name
    except Exception:
        return name


def _demangle(name):
    m = re.match(r'^_vt[.$](.*)$', name)
    if m:
        parts = m.group(1).split('.')
        out = []
        for p in parts:
            d = _DM(p)
            out.append(d.classname())
        return 'vtable for ' + ' in '.join(out)
    if name.startswith('_._') or name.startswith('_$_'):
        d = _DM(name[3:])
        cls = d.classname()
        return '%s::~%s()' % (cls, re.sub(r'<.*', '', cls.split('::')[-1]))
    # constructor: __<class><args>
    if name.startswith('__') and len(name) > 2 and (name[2].isdigit() or name[2] in 'Qt'):
        d = _DM(name[2:])
        cls = d.classname()
        d.tbias = 1
        args = d.arglist()
        return '%s::%s(%s)' % (cls, re.sub(r'<.*', '', cls.split('::')[-1]), args)
    # find the separator "__" (skip leading underscores of operator names)
    start = 2 if name.startswith('__') else 1
    pos = start
    while True:
        k = name.find('__', pos)
        if k < 0:
            return None
        base, rest = name[:k], name[k + 2:]
        if not rest:
            pos = k + 1
            continue
        try:
            return _demangle_split(base, rest)
        except Exception:
            pos = k + 1


def _demangle_split(base, rest):
    if base.startswith('__'):
        op = base[2:]
        if op in _OPS:
            base = _OPS[op]
        elif op.startswith('op'):
            d0 = _DM(op[2:])
            base = 'operator ' + d0.type()
    d = _DM(rest)
    const = ''
    if d.peek() == 'H':          # template function: H<n><targs>_[class]<args>_<ret>
        d.i += 1
        n = d.count()
        targs = []
        for _ in range(n):
            if d.peek() == 'Z':
                d.i += 1
                targs.append(d.type())
            else:
                d.type()
                targs.append(str(d.num()) if d.peek().isdigit() else '?')
        if d.peek() != '_':
            raise ValueError('H')
        d.i += 1
        d.targs = targs
        cls = ''
        if d.peek() == 'C' and d.s[d.i + 1:d.i + 2].isdigit():
            d.i += 1
            const = ' const'
        if d.peek().isdigit() or d.peek() in 'Qt':
            cls = d.classname() + '::'
        d.tbias = 1 if cls else 0
        args = d.arglist(stop='_')
        return '%s%s<%s>(%s)%s' % (cls, base, ', '.join(targs), '' if args == 'void' else args, const)
    if d.peek() == 'F':
        d.i += 1
        d.tbias = 0
        args = d.arglist()
        return '%s(%s)' % (base, '' if args == 'void' else args)
    if d.peek() == 'C':
        d.i += 1
        const = ' const'
    if not (d.peek().isdigit() or d.peek() in 'Qt'):
        raise ValueError('no class')
    cls = d.classname()
    d.tbias = 1
    args = d.arglist()
    return '%s::%s(%s)%s' % (cls, base, '' if args == 'void' else args, const)


def short_demangled(dm):
    """Class::method without the argument list."""
    i = dm.find('(')
    return dm[:i] if i > 0 else dm


# ---------------------------------------------------------------------------
# helpers
# ---------------------------------------------------------------------------
_PRINT = set(range(0x20, 0x7f)) | {9, 10, 13}


def cstring_at(buf, off, minlen=4, maxlen=512):
    """Printable NUL-terminated string at buf[off], or None."""
    if off < 0 or off >= len(buf):
        return None
    e = buf.find(b'\0', off, off + maxlen + 1)
    if e < 0 or e - off < minlen:
        return None
    s = buf[off:e]
    if any(b not in _PRINT for b in s):
        return None
    if sum(1 for b in s if chr(b).isalnum()) < max(2, len(s) // 3):
        return None
    return s.decode('latin-1')


def norm_string(s):
    """Normalise a string for cross-build comparison (source paths -> lower-case tail)."""
    if re.search(r'\.(cpp|c|h|hpp)$', s, re.I) and ('/' in s or '\\' in s):
        p = s.replace('\\', '/').lower()
        parts = [x for x in p.split('/') if x and x != '..']
        return 'FILE:' + '/'.join(parts[-2:])
    return s


def is_float_plausible(v):
    import math
    if v != v or math.isinf(v):
        return False
    return v == 0.0 or 1e-6 < abs(v) < 1e9


# ---------------------------------------------------------------------------
# PC build
# ---------------------------------------------------------------------------
class PC:
    build = 'pc'

    def __init__(self, exe=PC_EXE, funcs=PC_FUNCS):
        import pefile
        self.path = exe
        pe = pefile.PE(exe, fast_load=True)
        pe.parse_data_directories(directories=[pefile.DIRECTORY_ENTRY['IMAGE_DIRECTORY_ENTRY_BASERELOC']])
        self.base = pe.OPTIONAL_HEADER.ImageBase
        self.img = pe.get_memory_mapped_image()
        self.sections = []
        for s in pe.sections:
            nm = s.Name.rstrip(b'\0').decode('latin-1')
            lo = self.base + s.VirtualAddress
            self.sections.append((nm, lo, lo + max(s.Misc_VirtualSize, s.SizeOfRawData)))
        self.text = [x for x in self.sections if x[0] == '.text'][0]
        relocs = []
        if hasattr(pe, 'DIRECTORY_ENTRY_BASERELOC'):
            for b in pe.DIRECTORY_ENTRY_BASERELOC:
                for e in b.entries:
                    if e.type == 3:
                        relocs.append(e.rva + self.base)
        self.relocs = sorted(relocs)
        fns = [json.loads(l) for l in open(funcs)]
        fns.sort(key=lambda f: f['entry'])
        self.funcs = {}
        for f in fns:
            size = sum(hi - lo for lo, hi in f['ranges'])
            self.funcs[f['entry']] = {'addr': f['entry'], 'name': f['name'], 'ranges': f['ranges'],
                                      'size': size, 'thunk': f.get('thunk', False)}
        # range index for fn_of
        rl = []
        for f in self.funcs.values():
            for lo, hi in f['ranges']:
                rl.append((lo, hi, f['addr']))
        rl.sort()
        self._rl = rl
        self._rlo = [r[0] for r in rl]
        self.an = _cached('pc', [exe, funcs], self._analyse)

    # -- raw access
    def section_of(self, a):
        for nm, lo, hi in self.sections:
            if lo <= a < hi:
                return nm
        return None

    def rd(self, a, n):
        o = a - self.base
        return self.img[o:o + n]

    def u32(self, a):
        return struct.unpack('<I', self.rd(a, 4))[0]

    def cstr(self, a, minlen=3):
        return cstring_at(self.img, a - self.base, minlen)

    def fn_of(self, a):
        i = bisect.bisect_right(self._rlo, a) - 1
        for k in range(i, max(i - 8, -1), -1):
            lo, hi, e = self._rl[k]
            if lo <= a < hi:
                return e
        return None

    def fmt(self, a):
        return '0x%06x' % a

    # -- analysis
    def _analyse(self):
        import capstone
        md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
        relset = set(self.relocs)
        tlo, thi = self.text[1], self.text[2]
        entries = set(self.funcs)
        hexre = re.compile(r'0x[0-9a-f]+|\b\d+\b')
        calls, refs, consts, ninstr = {}, {}, {}, {}
        for e, f in self.funcs.items():
            cl, rf, cs = [], [], []
            n = 0
            for lo, hi in f['ranges']:
                code = self.img[lo - self.base:hi - self.base]
                for (addr, size, mn, op) in md.disasm_lite(code, lo):
                    n += 1
                    if mn == 'call' or mn == 'jmp':
                        if op.startswith('0x'):
                            t = int(op, 16)
                            if mn == 'call' or (t in entries and t != e and not (lo <= t < hi)):
                                cl.append((addr, t, mn == 'jmp'))
                        # fallthrough to ref scan for 'call dword ptr [abs]'
                    # relocated operands inside this instruction
                    for r in range(addr + 1, addr + size - 3):
                        if r in relset:
                            t = struct.unpack_from('<I', self.img, r - self.base)[0]
                            kind = 'p'
                            if '[' in op and ('ptr [0x%x]' % t) in op:
                                if mn.startswith('f') or mn.endswith('ss') or mn.endswith('sd') or mn in ('movd', 'movq'):
                                    kind = 'f8' if 'qword' in op else ('f4' if 'dword' in op else 'm')
                                else:
                                    kind = 'm'
                            if tlo <= t < thi and t in entries and mn not in ('call',):
                                kind = 'fp'  # function pointer taken
                            rf.append((addr, t, kind))
                    # immediates (not addresses)
                    if mn in ('push', 'mov', 'cmp', 'and', 'or', 'xor', 'add', 'sub', 'test', 'imul'):
                        o2 = re.sub(r'\[[^\]]*\]', '', op)
                        for tok in hexre.findall(o2):
                            v = int(tok, 0)
                            if v >= 0x100 and not (self.base <= v < self.base + 0x500000):
                                cs.append(v & 0xffffffff)
            calls[e], refs[e], consts[e], ninstr[e] = cl, rf, cs, n
        return {'calls': calls, 'refs': refs, 'consts': consts, 'ninstr': ninstr}

    # -- derived views
    def callees(self, e):
        out = []
        for _, t, _ in self.an['calls'].get(e, []):
            if t not in out:
                out.append(t)
        return out

    def callgraph_rev(self):
        if not hasattr(self, '_rev'):
            rev = {}
            for e, cl in self.an['calls'].items():
                for _, t, _ in cl:
                    rev.setdefault(t, [])
                    if e not in rev[t]:
                        rev[t].append(e)
            self._rev = rev
        return self._rev

    def callers(self, e):
        return self.callgraph_rev().get(e, [])

    def strings_of(self, e):
        out = []
        for site, t, kind in self.an['refs'].get(e, []):
            if kind == 'p' or kind == 'm':
                s = self.cstr(t)
                if s is not None:
                    out.append((site, t, s))
        return out

    def floats_of(self, e):
        out = []
        for site, t, kind in self.an['refs'].get(e, []):
            if kind == 'f4':
                v = struct.unpack('<f', self.rd(t, 4))[0]
            elif kind == 'f8':
                v = struct.unpack('<d', self.rd(t, 8))[0]
            else:
                continue
            if is_float_plausible(v):
                out.append(float('%.6g' % v))
        return out

    def data_xrefs(self, target):
        """(site, function) of every relocated pointer to target."""
        out = []
        for e, rf in self.an['refs'].items():
            for site, t, kind in rf:
                if t == target:
                    out.append((site, e))
        # pointers in data (vtables etc.)
        b = struct.pack('<I', target)
        for r in self.relocs:
            if not (self.text[1] <= r < self.text[2]):
                if self.img[r - self.base:r - self.base + 4] == b:
                    out.append((r, None))
        return out

    def disasm(self, e):
        import capstone
        md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
        out = []
        for lo, hi in self.funcs[e]['ranges']:
            for (addr, size, mn, op) in md.disasm_lite(self.img[lo - self.base:hi - self.base], lo):
                out.append((addr, mn, op))
        return out

    def all_strings(self, minlen=4):
        """All NUL-terminated printable strings in .rdata/.data."""
        out = []
        for nm, lo, hi in self.sections:
            if nm not in ('.rdata', '.data'):
                continue
            buf = self.img[lo - self.base:hi - self.base]
            for m in re.finditer(rb'[\x20-\x7e\t\r\n]{%d,}\x00' % minlen, buf):
                out.append((lo + m.start(), m.group()[:-1].decode('latin-1')))
        return out

    # -- RTTI vtables
    def vtables(self):
        """{class_name: [slot targets]} for primary vtables found through MSVC RTTI."""
        if hasattr(self, '_vt'):
            return self._vt
        img, base = self.img, self.base
        rd_lo = [s for s in self.sections if s[0] == '.rdata'][0]
        da = [s for s in self.sections if s[0] == '.data'][0]
        tds = {}
        for m in re.finditer(rb'\.\?A[VU][^\x00]{1,200}\x00', img[da[1] - base:da[2] - base]):
            td = da[1] + m.start() - 8
            tds[td] = m.group()[:-1].decode('latin-1')
        relset = set(self.relocs)
        cols = {}
        for r in self.relocs:
            if rd_lo[1] <= r < rd_lo[2]:
                t = struct.unpack_from('<I', img, r - base)[0]
                if t in tds and r - 12 >= rd_lo[1]:
                    col = r - 12
                    sig, off, cd = struct.unpack_from('<III', img, col - base)
                    if sig == 0 and off == 0:
                        cols[col] = tds[t]
        vt = {}
        entries = set(self.funcs)
        for r in self.relocs:
            if rd_lo[1] <= r < rd_lo[2]:
                t = struct.unpack_from('<I', img, r - base)[0]
                if t in cols:
                    v = r + 4
                    slots = []
                    while v in relset:
                        f = struct.unpack_from('<I', img, v - base)[0]
                        if not (self.text[1] <= f < self.text[2]):
                            break
                        slots.append(f)
                        v += 4
                        if v in cols or (v + 0) in []:
                            break
                    name = msvc_class_name(cols[t])
                    if name not in vt or len(slots) > len(vt[name][1]):
                        vt[name] = (r + 4, slots)
        self._vt = vt
        return vt


def msvc_class_name(td):
    """'.?AVZGEOM@@' -> 'ZGEOM'; '.?AV?$CBaseEvent@VZCAMERA@@@@' -> 'CBaseEvent<ZCAMERA>'."""
    s = td[4:] if td.startswith('.?A') else td
    try:
        r, _ = _msvc_name(s, 0)
        return r
    except Exception:
        return s.rstrip('@')


def _msvc_name(s, i, names=None):
    # returns qualified name parsed from s[i:] (terminated by '@@'), handling ?$ templates and
    # single-digit back-references (V1@ = names[1] of the enclosing template scope).
    parts = []
    while i < len(s) and s[i] != '@':
        if s[i].isdigit() and names is not None:
            k = int(s[i])
            parts.append(names[k] if k < len(names) else '?')
            i += 1
            continue
        if s.startswith('?$', i):
            j = s.index('@', i)
            tname = s[i + 2:j]
            i = j + 1
            args = []
            tnames = [tname]
            while i < len(s) and s[i] != '@':
                c = s[i]
                ptr = ''
                while c in 'PQ' and i + 2 < len(s) and s[i + 1] in 'ABCD':
                    ptr += '*'; i += 2; c = s[i]
                if c in 'VU':
                    a, i = _msvc_name(s, i + 1, tnames)
                    a += ptr
                    args.append(a)
                    if a not in tnames:
                        tnames.append(a)
                elif c == '$' and s[i:i + 2] == '$0':
                    i += 2
                    k = i
                    while i < len(s) and s[i] != '@':
                        i += 1
                    args.append(s[k:i]); i += 1
                else:
                    args.append({'H': 'int', 'I': 'unsigned', 'M': 'float', 'N': 'double', 'D': 'char',
                                 'E': 'unsigned char', 'F': 'short', 'G': 'unsigned short'}.get(c, c))
                    i += 1
            i += 1
            parts.append('%s<%s>' % (tname, ', '.join(args)))
        else:
            j = s.index('@', i)
            parts.append(s[i:j])
            if names is not None and s[i:j] not in names:
                names.append(s[i:j])
            i = j + 1
    i += 1
    return '::'.join(reversed(parts)), i


# ---------------------------------------------------------------------------
# GameCube build
# ---------------------------------------------------------------------------
class GC:
    build = 'gc'

    def __init__(self, elf=GC_ELF):
        self.path = elf
        D = self.D = open(elf, 'rb').read()
        e_shoff = struct.unpack_from('>I', D, 0x20)[0]
        e_shentsize, e_shnum, e_shstrndx = struct.unpack_from('>HHH', D, 0x2e)
        sh = []
        for i in range(e_shnum):
            sh.append(struct.unpack_from('>10I', D, e_shoff + i * e_shentsize))
        shstr = sh[e_shstrndx]
        def nm(o, tab):
            e = D.index(b'\0', tab[4] + o)
            return D[tab[4] + o:e].decode('latin-1')
        self.sections = []
        symtab = strtab = None
        for i, s in enumerate(sh):
            name = nm(s[0], shstr)
            if s[1] in (1, 8) and s[3]:
                self.sections.append((name, s[3], s[3] + s[5], s[4] if s[1] == 1 else None))
            if s[1] == 2:
                symtab = s
                strtab = sh[s[6]]
        self.text = [x for x in self.sections if x[0] == '.text'][0]
        self.funcs = {}
        self.syms = []      # (addr, name, size, type)
        self.byname = {}
        n = symtab[5] // 16
        curfile = None
        cus = {}
        for k in range(n):
            st_name, st_value, st_size, st_info, st_other, st_shndx = struct.unpack_from('>IIIBBH', D, symtab[4] + k * 16)
            if not st_name:
                continue
            name = nm(st_name, strtab)
            typ = st_info & 15
            if typ == 4:
                curfile = name
            elif name == 'gcc2_compiled.' and self.text[1] <= st_value < self.text[2]:
                cus[st_value] = curfile or '?'
            self.syms.append((st_value, name, st_size, typ))
            if typ == 2 and st_size and self.text[1] <= st_value < self.text[2]:
                if st_value not in self.funcs:
                    self.funcs[st_value] = {'addr': st_value, 'name': name, 'size': st_size,
                                            'local': (st_info >> 4) == 0}
            self.byname.setdefault(name, []).append(st_value)
        # functions only present as plain symbols (no FUNC type) are not expected; keep FUNC set.
        self.syms.sort()
        # compilation units: each GCC object starts its .text with a 'gcc2_compiled.' label,
        # preceded in the symbol table by an STT_FILE symbol naming the source file.
        self.cu_starts = sorted(cus)
        self.cu_names = [cus[a] for a in self.cu_starts]
        self._saddr = [s[0] for s in self.syms]
        self._fstarts = sorted(self.funcs)
        self.sda = (self.byname.get('_SDA_BASE_') or [0])[0]
        self.sda2 = (self.byname.get('_SDA2_BASE_') or [0])[0]
        self.an = _cached('gc', [elf], self._analyse)

    def cu_of(self, a):
        """Index of the compilation unit containing a (or -1)."""
        return bisect.bisect_right(self.cu_starts, a) - 1

    def cu_name(self, a):
        i = self.cu_of(a)
        return self.cu_names[i] if i >= 0 else '?'

    def section_of(self, a):
        for nm, lo, hi, off in self.sections:
            if lo <= a < hi:
                return nm
        return None

    def rd(self, a, n):
        for nm, lo, hi, off in self.sections:
            if lo <= a < hi and off is not None:
                return self.D[off + a - lo:off + a - lo + n]
        return None

    def u32(self, a):
        b = self.rd(a, 4)
        return struct.unpack('>I', b)[0] if b and len(b) == 4 else None

    def cstr(self, a, minlen=3):
        for nm, lo, hi, off in self.sections:
            if lo <= a < hi and off is not None:
                return cstring_at(self.D[:off + hi - lo], off + a - lo, minlen)
        return None

    def fn_of(self, a):
        i = bisect.bisect_right(self._fstarts, a) - 1
        if i < 0:
            return None
        f = self.funcs[self._fstarts[i]]
        return f['addr'] if a < f['addr'] + f['size'] else None

    def symat(self, a):
        i = bisect.bisect_right(self._saddr, a) - 1
        while i >= 0 and self.syms[i][3] not in (1, 2) and self._saddr[i] == self._saddr[max(i, 0)] and i > 0 and self.syms[i - 1][0] == self.syms[i][0]:
            i -= 1
        if i < 0:
            return '?'
        s = self.syms[i]
        return s[1] if s[0] == a else '%s+0x%x' % (s[1], a - s[0])

    def fmt(self, a):
        return '%08x' % a

    def _analyse(self):
        D = self.D
        nm_, tlo, thi, toff = self.text
        valid = [(lo, hi) for nm, lo, hi, off in self.sections if nm not in ('.text', '.init')]
        def isdata(v):
            for lo, hi in valid:
                if lo <= v < hi:
                    return True
            return False
        calls, refs, consts = {}, {}, {}
        for e, f in self.funcs.items():
            off = toff + e - tlo
            known = {}
            cl, rf, cs = [], [], []
            for k in range(f['size'] // 4):
                w = struct.unpack_from('>I', D, off + 4 * k)[0]
                a = e + 4 * k
                op = w >> 26
                if op == 18:
                    li = w & 0x3fffffc
                    if li & 0x2000000:
                        li -= 0x4000000
                    t = li if (w & 2) else a + li
                    if w & 1:
                        cl.append((a, t, False))
                        for r in range(3, 13):
                            known.pop(r, None)
                    elif not (e <= t < e + f['size']) and t in self.funcs:
                        cl.append((a, t, True))   # tail call
                    continue
                rd_ = (w >> 21) & 31
                ra = (w >> 16) & 31
                simm = w & 0xffff
                if simm & 0x8000:
                    simm -= 0x10000
                if op == 15:  # addis / lis
                    if ra == 0:
                        known[rd_] = (w & 0xffff) << 16
                    elif ra in known:
                        known[rd_] = (known[ra] + ((w & 0xffff) << 16)) & 0xffffffff
                    else:
                        known.pop(rd_, None)
                    continue
                if op == 14:  # addi / li
                    base = 0 if ra == 0 else known.get(ra, self.sda if ra == 13 else self.sda2 if ra == 2 else None)
                    if base is None:
                        known.pop(rd_, None)
                        continue
                    v = (base + simm) & 0xffffffff
                    if ra == 0:
                        if abs(simm) >= 0x100:
                            cs.append(v)
                        known[rd_] = v
                        continue
                    if isdata(v):
                        rf.append((a, v, 'p'))
                        known.pop(rd_, None)
                    else:
                        known[rd_] = v
                        if v >= 0x10000:
                            cs.append(v)
                    continue
                if op == 24:  # ori rA,rS,uimm  (dest = ra field position bits 11-15)
                    rs_, rdst = rd_, ra
                    if rs_ in known:
                        v = known[rs_] | (w & 0xffff)
                        if isdata(v):
                            rf.append((a, v, 'p'))
                        elif v >= 0x10000:
                            cs.append(v)
                        known[rdst] = v
                    else:
                        known.pop(rdst, None)
                    continue
                if op in (32, 33, 34, 35, 40, 41, 42, 43, 36, 37, 38, 39, 44, 45, 48, 49, 50, 51, 52, 53, 54, 55):
                    base = known.get(ra, self.sda if ra == 13 else self.sda2 if ra == 2 else None)
                    if base is not None and ra != 0:
                        v = (base + simm) & 0xffffffff
                        if isdata(v):
                            kind = {48: 'f4', 49: 'f4', 50: 'f8', 51: 'f8'}.get(op, 'm')
                            rf.append((a, v, kind))
                    if op in (32, 33, 34, 35, 40, 41, 42, 43) and rd_ != ra:
                        known.pop(rd_, None)
                    continue
                if op == 31 or op in (21, 20, 23, 28, 29, 7, 8, 12, 13):
                    # integer ops writing rA (rlwinm, andi., ...) or rD: forget both
                    known.pop(ra, None)
                    if op == 31:
                        known.pop(rd_, None)
                    continue
                if op == 11 or op == 10:  # cmpwi / cmplwi immediates
                    if abs(simm) >= 0x100:
                        cs.append(simm & 0xffffffff)
            # function pointers taken (lis/addi pointing at a function entry)
            calls[e], refs[e], consts[e] = cl, rf, cs
        return {'calls': calls, 'refs': refs, 'consts': consts}

    def callees(self, e):
        out = []
        for _, t, _ in self.an['calls'].get(e, []):
            if t not in out:
                out.append(t)
        return out

    def callgraph_rev(self):
        if not hasattr(self, '_rev'):
            rev = {}
            for e, cl in self.an['calls'].items():
                for _, t, _ in cl:
                    rev.setdefault(t, [])
                    if e not in rev[t]:
                        rev[t].append(e)
            self._rev = rev
        return self._rev

    def callers(self, e):
        return self.callgraph_rev().get(e, [])

    def strings_of(self, e):
        out = []
        for site, t, kind in self.an['refs'].get(e, []):
            if kind in ('p', 'm'):
                s = self.cstr(t)
                if s is not None:
                    out.append((site, t, s))
        return out

    def floats_of(self, e):
        out = []
        for site, t, kind in self.an['refs'].get(e, []):
            b = self.rd(t, 8 if kind == 'f8' else 4)
            if kind == 'f4' and b and len(b) == 4:
                v = struct.unpack('>f', b)[0]
            elif kind == 'f8' and b and len(b) == 8:
                v = struct.unpack('>d', b)[0]
            else:
                continue
            if is_float_plausible(v):
                out.append(float('%.6g' % v))
        return out

    def data_xrefs(self, target):
        out = []
        for e, rf in self.an['refs'].items():
            for site, t, kind in rf:
                if t == target:
                    out.append((site, e))
        b = struct.pack('>I', target)
        for nm, lo, hi, off in self.sections:
            if off is None or nm in ('.text', '.init'):
                continue
            seg = self.D[off:off + hi - lo]
            i = seg.find(b)
            while i >= 0:
                if i % 4 == 0:
                    out.append((lo + i, None))
                i = seg.find(b, i + 1)
        return out

    def disasm(self, e):
        import capstone
        md = capstone.Cs(capstone.CS_ARCH_PPC, capstone.CS_MODE_32 | capstone.CS_MODE_BIG_ENDIAN)
        f = self.funcs[e]
        buf = self.rd(e, f['size'])
        out = []
        for o in range(0, len(buf), 4):
            L = list(md.disasm_lite(buf[o:o + 4], e + o))
            if not L:
                out.append((e + o, '.word', '0x' + buf[o:o + 4].hex()))
            else:
                out.append((L[0][0], L[0][2], L[0][3]))
        return out

    def all_strings(self, minlen=4):
        out = []
        for nm, lo, hi, off in self.sections:
            if off is None or nm in ('.text', '.init'):
                continue
            buf = self.D[off:off + hi - lo]
            for m in re.finditer(rb'[\x20-\x7e\t\r\n]{%d,}\x00' % minlen, buf):
                out.append((lo + m.start(), m.group()[:-1].decode('latin-1')))
        return out

    def vtables(self):
        """{class_name: (addr, [slot targets])} from _vt.<class> symbols (8-byte GCC2 entries)."""
        if hasattr(self, '_vt'):
            return self._vt
        vt = {}
        for a, name, size, typ in self.syms:
            if not name.startswith('_vt.') and not name.startswith('_vt$'):
                continue
            rest = name[4:]
            if '.' in rest or '$' in rest:   # secondary vtable (MI) - skip
                continue
            try:
                cls = _DM(rest).classname()
            except Exception:
                continue
            slots = []
            n = size // 8 if size else 0
            for k in range(1, n):
                t = self.u32(a + 8 * k + 4)
                slots.append(t if t else 0)
            vt[cls] = (a, slots)
        self._vt = vt
        return vt


# ---------------------------------------------------------------------------
# name map
# ---------------------------------------------------------------------------
def load_namemap(path=NAMEMAP):
    rows = []
    if not os.path.exists(path):
        return rows
    with open(path) as f:
        hdr = None
        for line in f:
            if line.startswith('#'):
                continue
            p = line.rstrip('\n').split('\t')
            if hdr is None:
                hdr = p
                continue
            r = dict(zip(hdr, p))
            r['gc_addr_i'] = int(r['gc_addr'], 16)
            r['pc_addr_i'] = int(r['pc_addr'], 16)
            rows.append(r)
    return rows

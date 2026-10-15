"""specs_s90003.py - hard trial (fable) batch 90003: 0x5fc590 script manager LoadScript(path, ctx, flag).
The engine's begin/end/cap string helpers (ctor 0x42b390, substr 0x4312f0, assign 0x5f2d60, append 0x5f2c60, find 0x5fa640 / 0x5f1050 / 0x5fba50,
replace 0x5fd630, free 0x54f870, alloc 0x41e290 / free 0x634273) run REAL on both sides; they allocate through the allocator object at 0x70038c,
whose slots 8 (alloc) and 0x10 (free) are deterministic stubs (bump allocation from the emulator heap, so both sides get the same addresses; a
0x17e request returns the prepared script node). memmove import stubbed. Hooked with custom recorders: map find 0x5fb980 (writes the iterator:
header = not found, or a found node), map insert 0x5fb110 (returns a heap slot), node ctor 0x5fa740, parse 0x607640 (records the stream struct:
5 dwords + the flag byte, whose dword has junk upper bytes), 0x5fd0a0, 0x5ff2b0 and the recursive LoadScript (flag recorded as its low byte;
the hook passes the top-level entry through by checking the return address), loader global [0x724270] slots 8 / 0x14 / 0xc, assert hook, /GS."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub, stub_memmove, _HOOKED


def _cstr(em, p, limit=0x200):
    s = b''
    while len(s) < limit:
        ch = em.rbytes(p, 1)
        if ch == b'\0':
            break
        s += ch
        p += 1
    return s


def _sval(em, s):   # content of a begin/end string object at s (the object may live on the stack)
    b, e_ = em.r32(s), em.r32(s + 4)
    return em.rbytes(b, e_ - b) if 0 < e_ - b < 0x1000 else b'<bad %x %x>' % (b, e_)


PATHS = [b'data\\scripts\\Foo.SRC', b'foo', b'', b'a.b\\c', b'x\\y\\z.ppo', b'Dir\\sub.dir\\name', b'.hidden', b'trail\\', b'one.two.three',
         b'C:\\Game\\Scripts\\Level01.src', b'\\lead', b'UPPER.CASE\\Mixed.Src']


def _g5fc590(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    stub_memmove(c)

    def memcpy(em, res_):   # VCRUNTIME memcpy import, cdecl (dst, src, n) -> dst
        d, s_, n = em.arg32(0), em.arg32(1), em.arg32(2)
        if n:
            em.wbytes(d, em.rbytes(s_, n))
        em.ret(eax=d, argbytes=0)
    e.stub_import('memcpy', memcpy)
    hook_rec(c, 0x633654, 0, pop=0, ret=lambda em, k: em.reg('eax'))

    def ah(em, res_):
        em.calllog.append(('assert',))
        em.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))

    # ---- allocator object at 0x70038c: slot 8 alloc(size) thiscall, slot 0x10 free(p) thiscall
    node = e.alloc(0x180, 4)
    e.wbytes(node, bytes(r.getrandbits(8) for _ in range(0x180)))
    parent = r.choice([b'', b'', b'parent.src', b'Base\\common.SRC', b'p'])
    pb = e.alloc(0x40, 4)
    e.wbytes(pb, parent + b'\0')
    e.w32(node + 0xc, pb)
    e.w32(node + 0x10, pb + len(parent))
    e.w32(node + 0x14, pb + 0x40)
    e.w32(node + 0x38, 0 if r.random() < 0.4 else obj(c, 0x10, {0: pystub(c, 1, this=True)}))
    e.w32(node + 0x2c, r.choice([0, 1, 7, r.getrandbits(16)]))
    e.wbytes(node + 0x172, bytes(12))

    def alloc(em, res_):
        n = em.arg32(0)
        if n == 0x17e:
            p = node
        else:
            p = em.alloc(n, 4)
        em.calllog.append(('alloc', n, p))
        em.ret(eax=p, argbytes=4)

    def free(em, res_):
        em.calllog.append(('free', em.arg32(0)))
        em.ret(eax=0, argbytes=4)
    e.w32(0x70038c, obj(c, 0x10, {8: e.stub_fn('alloc', alloc), 0x10: e.stub_fn('free', free)}))

    # ---- script manager object: byte 0 = disabled flag, +1 = map header pointer
    self_ = rnd(c, 0x40)
    e.wbytes(self_, bytes([r.choice([0, 0, 0, 0, 0, 1, 0xff])]))
    header = rnd(c, 0x40)
    e.wbytes(self_ + 1, header.to_bytes(4, 'little'))
    found = rnd(c, 0x40)
    is_found = r.random() < 0.25
    slot = e.alloc(8, 4)

    def mfind(em, res_):
        em.calllog.append(('mapfind', em.reg('ecx'), _sval(em, em.arg32(1))))
        em.w32(em.arg32(0), found if is_found else header)
        em.ret(eax=em.arg32(0), argbytes=8)

    def mins(em, res_):
        em.calllog.append(('mapins', em.reg('ecx'), _sval(em, em.arg32(0))))
        em.ret(eax=slot, argbytes=4)

    def ctor(em, res_):
        em.calllog.append(('nodector', em.reg('ecx')))
        em.ret(eax=em.reg('ecx'), argbytes=0)

    def parse(em, res_):
        st = em.arg32(0)
        em.calllog.append(('parse', em.reg('ecx'), tuple(em.r32(st + 4 * i) for i in range(5)), em.rbytes(st + 0x14, 1)))
        em.ret(eax=0, argbytes=4)

    def d0a0(em, res_):
        em.calllog.append(('5fd0a0', em.reg('ecx'), _sval(em, em.arg32(0))))
        em.ret(eax=0, argbytes=4)

    def f2b0(em, res_):
        em.calllog.append(('5ff2b0', em.reg('ecx'), em.arg32(0), em.arg32(1), em.arg32(2) & 0xff))
        em.ret(eax=0, argbytes=12)
    rec_ret = r.getrandbits(32)

    def recur(em, res_):
        if em.r32(em.reg('esp')) == em.RET_ADDR:
            return   # the top-level entry of the function under test: run it
        em.calllog.append(('recurse', em.reg('ecx'), _cstr(em, em.arg32(0)), em.arg32(1), em.arg32(2) & 0xff))
        em.ret(eax=rec_ret, argbytes=12)
    for a, h in ((0x5fb980, mfind), (0x5fb110, mins), (0x5fa740, ctor), (0x607640, parse), (0x5fd0a0, d0a0), (0x5ff2b0, f2b0), (0x5fc590, recur)):
        e.hook(a, h)
        _HOOKED.add(a)

    # ---- loader global: slot 8 (path, &size) -> data block or 0; slots 0x14 / 0xc cdecl error log
    dsize = r.choice([1, 16, 100, 0x300])
    data = rnd(c, dsize)
    has_data = r.random() < 0.7

    def load(em, res_):
        em.calllog.append(('load', _cstr(em, em.arg32(0))))
        if has_data:
            em.w32(em.arg32(1), dsize)
            em.ret(eax=data, argbytes=8)
        else:
            em.ret(eax=0, argbytes=8)

    def err14(em, res_):
        em.calllog.append(('err14', em.arg32(2), _cstr(em, em.arg32(3))))
        em.wbytes(em.arg32(1), b'formatted error text\0')
        em.ret(eax=0, argbytes=0)

    def err0c(em, res_):
        em.calllog.append(('err0c', _cstr(em, em.arg32(1))))
        em.ret(eax=0, argbytes=0)
    e.w32(0x724270, obj(c, 0x20, {8: e.stub_fn('load', load), 0x14: e.stub_fn('err14', err14), 0xc: e.stub_fn('err0c', err0c)}))
    e.w32(found + 0x19, r.getrandbits(32))

    path = r.choice(PATHS + [bytes(r.choice(b'abcXYZ.\\') for _ in range(r.randint(0, 24)))])
    pa = e.alloc(len(path) + 1, 1)
    e.wbytes(pa, path + b'\0')
    ctx = r.choice([0, 0, rnd(c, 0x20)])
    return [self_, pa, ctx, r.choice([0, 1, 0x100, 0x1ff, r.getrandbits(32)])]


S(0x5fc590, 'GUESS script manager LoadScript', 'thiscall', None, ret='eax', gen=_g5fc590, note='batch90003')

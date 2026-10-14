"""specs_s34055.py - cascade tier E, batch 34055.
0x420ea0 (cdecl): the imports GetModuleFileNameA (writes a random path with backslashes and logs its value arguments) and strrchr (a real strrchr in Python, logging the scanned string) are stubbed; 0x4cbe80 logs the string it
receives (stack pointer, read up to the terminator) and 0x633654 is a zero-argument recorder; the exe's own 10 bytes at 0x677a60 are appended.
0x447bf0: hooked 0x45c680 / 0x4dc630 / 0x4dbb00; [this+8] is an object whose dword at +0x68 is zero in a fifth; f is zero in half the cases; the observer at the unaligned engine table +0x5d35 is null in a quarter (slot 0x14).
0x454da0: [this+0x5c] is an object with slots 0xc and 4 (recorders); the record [a+0xc] carries 0x1000f0 at +0x23 in two thirds; [a+0x5c] is null in a seventh, else an iterator object (slots 0x4c, 0x5c; 0..3 ids); hooked 0x43f8c0."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec, sysobj


def _g420ea0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def gmfn(em, res_):
        buf = em.arg32(1)
        segs = [bytes(r.randrange(0x41, 0x7b) for _ in range(r.randint(1, 8))) for _ in range(r.randint(0, 4))]
        path = (b'\\'.join(segs) if r.random() < 0.8 else b''.join(segs))[:200] + b'\0'
        em.wbytes(buf, path)
        em.calllog.append(('GetModuleFileNameA', em.arg32(0), em.arg32(2)))
        em.ret(eax=len(path) - 1, argbytes=12)

    def strrchr(em, res_):
        s, ch = em.arg32(0), em.arg32(1) & 0xff
        data = b''
        i = 0
        while True:
            b = bytes(em.rbytes(s + i, 1))
            if b == b'\0':
                break
            data += b
            i += 1
        em.calllog.append(('strrchr', ch, data))
        pos = data.rfind(bytes([ch]))
        em.ret(eax=(s + pos) if pos >= 0 else 0, argbytes=0)
    e.stub_import('GetModuleFileNameA', gmfn)
    e.stub_import('strrchr', strrchr)

    def logstr(em, k):
        p = em.arg32(0)
        data = b''
        i = 0
        while i < 0x400:
            b = bytes(em.rbytes(p + i, 1))
            if b == b'\0':
                break
            data += b
            i += 1
        em.calllog.append(('path', data))
    hook_rec(c, 0x4cbe80, 1, this=True, side=logstr, stackmark=(0,))
    hook_rec(c, 0x633654, 0, pop=0, ret=None)   # the real /GS check leaves EAX alone (this function returns its argument in EAX)
    return [rnd(c, 0x20)]


def _g447bf0(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x45c680, 1, this=True)
    hook_rec(c, 0x4dc630, 2, this=True)
    hook_rec(c, 0x4dbb00, 1, this=True)
    o = rnd(c, 0x80)
    c.emu.w32(o + 0x68, 0 if r.random() < 0.2 else r.getrandbits(32) | 1)
    observer = 0 if r.random() < 0.25 else obj(c, 0x20, {0x14: pystub(c, 1, this=True)}, nslots=0x18 // 4)
    so = sysobj(c, table_size=0x5e00)
    tbl = c.emu.r32(so + 0x9b)
    c.emu.wbytes(tbl + 0x5d35, observer.to_bytes(4, 'little'))
    me = rnd(c, 0x40)
    c.emu.w32(me + 8, o)
    f = 0 if r.random() < 0.5 else r.choice([1, 0x100, r.getrandbits(32) | 1])
    return [me, f]


def _g454da0(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x43f8c0, 1, this=True)
    n = r.choice([0, 1, 2, 3])

    def begin(em, k):
        for i in range(3):
            em.w32(em.arg32(0) + 4 * i, r.getrandbits(32))

    def nxt(em, k):
        em.w32(em.arg32(0), 1 if k < n else 0)
    it = 0 if r.random() < 1 / 7 else obj(c, 0x20, {0x4c: pystub(c, 1, this=True, side=begin, stackmark=(0,)),
                                                    0x5c: pystub(c, 1, this=True, side=nxt, stackmark=(0,), ret=lambda em, k: r.getrandbits(32))},
                                          nslots=0x60 // 4)
    rec = rnd(c, 0x40)
    c.emu.wbytes(rec + 0x23, (0x1000f0 if r.random() < 2 / 3 else r.getrandbits(32)).to_bytes(4, 'little'))
    a = rnd(c, 0x80)
    c.emu.w32(a + 0xc, rec)
    c.emu.w32(a + 0x5c, it)
    m = obj(c, 0x20, {0xc: pystub(c, 0, this=True), 4: pystub(c, 1, this=True)}, nslots=0x10 // 4)
    me = rnd(c, 0x80)
    c.emu.w32(me + 0x5c, m)
    return [me, a]


S(0x420ea0, 'GUESS build path of error.log next to the executable', 'cdecl', None, ret='eax', gen=_g420ea0, note='batch34055')
S(0x447bf0, 'GUESS flag an entry and tell the observer', 'thiscall', None, ret=None, gen=_g447bf0, note='batch34055')
S(0x454da0, 'GUESS copy child list when the source has a given kind', 'thiscall', None, ret=None, gen=_g454da0, note='batch34055')

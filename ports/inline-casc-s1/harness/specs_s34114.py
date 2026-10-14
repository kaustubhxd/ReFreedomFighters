"""specs_s34114.py - 0x4d2a20: 0..3 records (dword size, flag byte, unaligned string length, string), total size at +0xc (sometimes short), idx 0..2, cap around len + 1; the assert hook word is a recorder stub, memcpy is a recorder."""
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec


def _g4d2a20(c):
    clear_hooks(c)
    r = c.rng

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    c.emu.w32(0x7003b0, c.emu.stub_fn('assert hook', ah))
    hook_rec(c, 0x634d22, 3, pop=0, ret=r.getrandbits(32))
    me = rnd(c, 0x20)
    buf = rnd(c, 0x100)
    off = 0
    lens = []
    for i in range(r.choice([0, 1, 2, 3])):
        ln = r.choice([0, 1, 4, 9])
        size = 0x11 + ln + 1
        c.emu.w32(buf + off, size)
        c.emu.wbytes(buf + off + 4, bytes([r.choice([0, 1, 1, 7])]))
        c.emu.wbytes(buf + off + 5, ln.to_bytes(4, 'little'))
        lens.append(ln)
        off += size
    if r.random() < 0.15:
        c.emu.w32(buf + off, 1)
        c.emu.wbytes(buf + off + 4, bytes([r.choice([0, 1])]))
        c.emu.wbytes(buf + off + 5, bytes(4))
        total = off + 1
    else:
        total = off if r.random() < 0.8 else max(0, off - r.choice([1, 5, 20]))
    c.emu.w32(me + 8, buf)
    c.emu.w32(me + 0xc, total)
    ln = r.choice(lens) if lens else 3
    cap = r.choice([ln + 1, ln, ln + 2, 0x20, 0xffffffff])
    return [me, rnd(c, 0x40), cap, r.choice([0, 0, 1, 2])]


S(0x4d2a20, 'GUESS copy the idx-th flagged record string', 'thiscall', None, ret='al', gen=_g4d2a20, note='batch34114')

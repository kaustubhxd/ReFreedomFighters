"""specs_s38033.py - cascade s8 batch 38033. Mode (this[0x10]) is 2, 3, 4 or an unknown value; mode 3 texts of 0..5 bytes, mostly built from the 3 characters at 0x6b8788 (read from the image) so equal /
longer / shorter / different cases run; the strncmp import (0x676408) is a logged Python stub; 0x5fb8b0 (true 40% each, per pattern) / 0x602cd0 / 0x50d7b0 hooked (the last two record the dword their
out pointer refers to); mode 4 has this[0x1c] zero 15% of the time, the maker object y (null 20%) with a recording slot 0 (2 args), x tag byte in {0, 4, other} with x[0] an object with slot 0x28;
the logger stream and the assert hook are always set."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _g602e00(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    st = obj(c, 0x20, {0x2c: pystub(c, 3, pop=0)})

    def lg(em, res_):
        em.calllog.append(('logger', em.reg('ecx') != 0, em.arg32(0), em.arg32(1)))
        em.ret(eax=st, argbytes=8)
    e.w32(0x700390, obj(c, 0x40, {0x20: e.stub_fn('logger', lg)}))
    e.w32(0x7003b0, e.stub_fn('assert hook', lambda em, res_: (em.calllog.append(('assert',)), em.ret(eax=r.getrandbits(32)))))

    def cmpstub(em, res_):
        a, b, n = em.arg32(0), em.arg32(1), em.arg32(2)
        sa, sb = em.rbytes(a, n), em.rbytes(b, n)
        em.calllog.append(('cmp', sa, sb, n))
        em.ret(eax=0 if sa == sb else (1 if sa > sb else 0xffffffff), argbytes=0)
    e.w32(0x676408, e.stub_fn('strncmp', cmpstub))
    pat = e.rbytes(0x6b8788, 3)
    tl = r.choice([0, 1, 2, 3, 3, 3, 4, 5])
    txt = bytearray(pat[:tl] if r.random() < 0.7 else r.randbytes(tl))
    txt += bytes(max(0, tl - len(txt)))
    txt = bytes(txt) + b'\0' * 4
    buf = e.alloc(len(txt) + 8, 4)
    e.wbytes(buf, txt + r.randbytes(8))
    mode = r.choice([2, 3, 3, 3, 4, 4, 4, 5, 0])
    me = rnd(c, 0x40)
    e.w32(me + 0x10, mode)
    e.w32(me + 4, buf)
    e.w32(me + 8, buf + tl)
    old = obj(c, 0x20, {0x28: pystub(c, 0, this=True)})
    x = rnd(c, 0x10)
    e.w32(x, old)
    e.wbytes(x + 4, bytes([r.choice([0, 4, 4, 1, 2])]))
    maker = obj(c, 0x20, {0: pystub(c, 2, this=True, ret=lambda em, k: r.getrandbits(32))})
    maker2 = obj(c, 0x20, {0: pystub(c, 2, this=True, ret=lambda em, k: r.getrandbits(32))})
    e.w32(me + 0x1c, 0 if r.random() < 0.15 else maker2)
    y = 0 if r.random() < 0.2 else maker
    hook_rec(c, 0x5fb8b0, 1, this=True, pop=4, ret=lambda em, k: r.choice([0, 1, 0x100]))
    hook_rec(c, 0x602cd0, 1, this=True, pop=4, deref={0: 1})
    hook_rec(c, 0x50d7b0, 1, this=True, pop=4, deref={0: 1})
    return [me, x, y]


S(0x602e00, 'GUESS convert parsed value by mode', 'thiscall', None, ret=None, gen=_g602e00, note='batch38033')

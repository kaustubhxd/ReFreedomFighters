"""specs_s67524.py - cascade s6 batch 67524 (0x46d2d0, stdcall(factory, src, key, show) ret 0x10, returns eax). The factory's slot 0x1c0 (5 args, callee pops) returns a new object (or 0);
the new object has slots 0x2c, 0x100 (lookup returning a helper with slot 0x54), 0x74 (matrix / vector pointers on the stack, content logged), 0x50 (advances a scripted child chain through an
out pointer); children carry flags at +0x3c and optional sub-objects at +0x54 (slots 0x154 / 0x158); 0x4dc630, 0x4db2c0 (writes the stack matrix / vector) and 0x4da340 are hooks."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub
from unicorn.x86_const import UC_X86_REG_ECX


def _w(c, a, v, n=4):
    c.emu.wbytes(a, (v & ((1 << (8 * n)) - 1)).to_bytes(n, 'little'))


def _g46d2d0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    nch = r.choice([0, 1, 2, 3])
    children = []
    for _ in range(nch):
        ch = rnd(c, 0x60)
        _w(c, ch + 0x3c, r.choice([0, 0x800000, 0x1, 0xff800000]))
        if r.random() < 0.7:
            sub = obj(c, 0x20, {0x154: pystub(c, 0, this=True), 0x158: pystub(c, 0, this=True)})
            _w(c, ch + 0x54, sub)
        else:
            _w(c, ch + 0x54, 0)
        children.append(ch)
    st = {'i': 0}

    def s50(em, k):
        st['i'] += 1
        em.w32(em.arg32(0), children[st['i']] if st['i'] < nch else 0)
    helper = obj(c, 0x20, {0x54: pystub(c, 1, this=True)})

    def s74(em, k):
        em.calllog.append(('74', em.rbytes(em.arg32(0), 0x24), em.rbytes(em.arg32(1), 12)))
    newo = obj(c, 0x40, {0x2c: pystub(c, 0, this=True), 0x100: pystub(c, 1, this=True, ret=lambda em, k: helper if r.random() < 0.6 else 0),
                         0x74: pystub(c, 2, this=True, stackmark=(0, 1), side=s74), 0x50: pystub(c, 1, this=True, stackmark=(0,), side=s50)})
    _w(c, newo + 8, children[0] if children else 0)
    ok = r.random() < 0.85
    factory = obj(c, 0x20, {0x1c0: pystub(c, 5, this=True, ret=newo if ok else 0)})
    hook_rec(c, 0x4dc630, 2, this=True)
    hook_rec(c, 0x4da340, 4, this=True)

    def h2c0(em, res_):
        em.wbytes(em.arg32(0), bytes((r_i * 7 + 3) & 0xff for r_i in range(0x24)))
        em.wbytes(em.arg32(1), bytes((r_i * 5 + 1) & 0xff for r_i in range(12)))
        em.calllog.append(('4db2c0', em.reg('ecx')))
        em.ret(eax=0, argbytes=8)
    e.hook(0x4db2c0, h2c0)
    src = rnd(c, 0x20)
    _w(c, src + 8, rnd(c, 0x40))
    return [factory, src, r.getrandbits(32), r.choice([0, 1, 1, 0x100])]


S(0x46d2d0, 'GUESS spawn_child', 'stdcall', None, ret='eax', gen=_g46d2d0, note='batch67524')

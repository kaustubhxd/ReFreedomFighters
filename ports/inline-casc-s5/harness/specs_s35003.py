"""specs_s35003.py - 0x51fbe0. Object (0x1800 random bytes) with an embedded object at +0x1684 (vtable slots 8 (1 arg), 0xc (returns al, random), 4 (2 args), all recorded);
dword +0x1658 zero in a third; unaligned dword +0x16d5 zero in half. Hooked 0x51f930 (thiscall), 0x4de040 (fastcall ecx = out buffer (filled with random bytes), edx = src recorded, one stack arg),
0x514890 (thiscall, 6 stack args; the local buffer arg compared by content)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _g51fbe0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    me = rnd(c, 0x1800)
    ret_al = r.choice([0, 1, r.getrandbits(8)])
    o = obj(c, 4, {8: pystub(c, 1, this=True), 0xc: pystub(c, 0, ret=ret_al, this=True), 4: pystub(c, 2, this=True)})
    e.w32(me + 0x1684, e.r32(o))
    if r.random() < 1 / 3:
        e.w32(me + 0x1658, 0)
    z = 0 if r.random() < 0.5 else r.getrandbits(32) | 1
    e.wbytes(me + 0x16d5, z.to_bytes(4, 'little'))
    hook_rec(c, 0x51f930, 0, this=True)
    data = bytes(r.getrandbits(8) for _ in range(0x24))

    def h(em, rr):
        em.calllog.append(('4de040', em.reg('edx'), em.arg32(0)))
        em.wbytes(em.reg('ecx'), data)
        em.ret(eax=0, argbytes=4)
    e.hook(0x4de040, h)
    hook_rec(c, 0x514890, 6, this=True, deref={2: -0x24})
    return [me]


S(0x51fbe0, 'GUESS refresh state and forward', 'thiscall', None, ret=None, gen=_g51fbe0, note='batch35003')

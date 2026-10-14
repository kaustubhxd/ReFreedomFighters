"""specs_s38011.py - cascade s8 batch 38011: 0x5c8a80. The eleven id globals (u16 at 0x714350, 0x714354, ... 0x71437c) get distinct random values per case; the id argument
is one of them (or unrelated). Helpers hooked; the table object (engine +0x9b) slot 0x58 maps its argument to a random value; this[0x44] slot 0x288 and the logger are
recording stubs. +0x88 is zero, equal to the argument or different (so every arm of the 0x714374 case runs); *out targets are heap words."""
import struct
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub

GL = [0x714350, 0x714354, 0x714358, 0x71435c, 0x714360, 0x714364, 0x714368, 0x71436c, 0x714370, 0x714374, 0x71437c]


def _g5c8a80(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    ids = r.sample(range(1, 0x10000), len(GL))
    for a, v in zip(GL, ids):
        e.wbytes(a, struct.pack('<H', v))
    st2 = obj(c, 0x20, {0x2c: pystub(c, 2, pop=0)})

    def lg(em, res_):
        em.calllog.append(('logger', em.reg('ecx') != 0, em.arg32(0), em.arg32(1)))
        em.ret(eax=st2, argbytes=8)
    e.w32(0x700390, obj(c, 0x40, {0x20: e.stub_fn('logger', lg)}))
    sysobj(c, {}, table_slots={0x58: pystub(c, 1, this=True, ret=lambda em, k: r.getrandbits(32))})
    me = obj(c, 0x100, {})
    e.w32(me + 0x44, obj(c, 0x20, {0x288: pystub(c, 3, this=True)}))
    for off in (0x70, 0x74, 0x80):
        e.w32(me + off, r.getrandbits(32))
    out = rnd(c, 0x10)
    e.w32(me + 0x88, r.choice([0, 0, out, r.getrandbits(32)]))
    for a in (0x5c82a0, 0x5c8470, 0x5c87f0, 0x5c90b0, 0x5c9330):
        hook_rec(c, a, 1, this=True, pop=4)
    hook_rec(c, 0x5c9130, 2, this=True, pop=8)
    hook_rec(c, 0x5c94f0, 0, this=True, ret=lambda em, k: r.choice([0, 0, 1, r.getrandbits(32)]))
    if r.random() < 0.9:
        idv = r.choice(ids)
    else:
        idv = r.randrange(0x10000)
    if r.random() < 0.3:
        idv |= r.getrandbits(16) << 16
    arg = out
    if idv & 0xffff == ids[4] and r.random() < 0.3:
        arg = 0
    elif idv & 0xffff == ids[9] and r.random() < 0.3:
        arg = r.choice([0, r.getrandbits(32)])
        if arg == 0:
            arg = e.r32(me + 0x88)   # equal to +0x88: the call arm
    elif idv & 0xffff in (ids[1], ids[2], ids[3], ids[7], ids[4]) and r.random() < 0.5:
        arg = r.getrandbits(32)
    return [me, idv, arg]


S(0x5c8a80, 'GUESS property dispatch by id', 'thiscall', None, ret='eax', gen=_g5c8a80, note='batch38011')

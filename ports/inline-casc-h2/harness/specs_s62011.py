from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def g4b0e40(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    new_value = r.getrandbits(32)

    def fill_out(emu, call_no):
        emu.w32(emu.arg32(0), new_value)

    hook_rec(c, 0x6352f0, 1, this=True, pop=4, deref={0: 1}, side=fill_out)
    slot = pystub(c, 1, this=True, pop=4, deref={0: 1})
    me = obj(c, 0x70, {0x98: slot}, nslots=0x99 // 4)
    e.w32(me + 0x38, r.getrandbits(32))
    e.w32(me + 0x50, r.getrandbits(32))
    e.w8(me + 0x6c, r.getrandbits(8))
    return [me]


S(0x4b0e40, 'GUESS refresh object cache and dirty flag', 'thiscall', None, ret=None, gen=g4b0e40, note='batch62011')

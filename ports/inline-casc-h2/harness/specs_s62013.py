from pilot import S
from recruits_util import obj, rnd, clear_hooks, hook_rec, pystub


def g5516e0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    collection = obj(c, 0x20, {0x4c: pystub(c, 0, this=True, ret=rnd(c, 0x20))})
    found = collection if r.random() < 0.7 else 0
    source = obj(c, 0x20, {0x18: pystub(c, 1, this=True, ret=found)})
    cursor = rnd(c, 0x20)
    helper_result = rnd(c, 0x20)

    def first_side(emu, call_no):
        emu.calllog.append(('index', emu.reg('ecx'), emu.arg32(0)))

    def second_side(emu, call_no):
        emu.calllog.append(('value', emu.reg('ecx'), emu.arg32(0)))

    hook_rec(c, 0x5003d0, 1, this=True, pop=4, ret=helper_result, side=first_side)
    hook_rec(c, 0x5002f0, 1, this=True, pop=4, ret=r.getrandbits(32), side=second_side)
    # The slot's return is fixed to a valid cursor address for any nonnull collection.
    e.w32(collection + 0x4c, pystub(c, 0, this=True, ret=cursor))
    return [source, r.getrandbits(32), rnd(c, 4)]


S(0x5516e0, 'GUESS find and process collection element', 'stdcall', None, ret='eax', gen=g5516e0, note='batch62013')

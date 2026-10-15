from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def gen(c):
    clear_hooks(c)
    r, e = c.rng, c.emu
    item = obj(c, 0x70, {0x60: pystub(c, 2, this=True, pop=8,
        side=lambda emu, k: emu.calllog.append(('item', emu.reg('ecx'), emu.arg32(0), emu.arg32(1))))})
    item_ret = r.getrandbits(32)
    global_obj = rnd(c, 0x200)
    get_item = pystub(c, 0, ret=item, side=lambda emu, k: emu.calllog.append(('get-item', emu.reg('ecx'))))
    query = pystub(c, 2, this=True, pop=8, ret=item_ret,
        side=lambda emu, k: emu.calllog.append(('query', emu.reg('ecx'), emu.arg32(0), emu.arg32(1))))
    collection = obj(c, 0x150, {0x138: get_item, 0x4c: query})
    e.w32(global_obj + 0x9b, collection)
    e.w32(0x70039c, global_obj)
    end = pystub(c, 2, this=True, pop=8,
        side=lambda emu, k: emu.calllog.append(('end', emu.reg('ecx'), emu.arg32(0), emu.arg32(1))))
    tail_ret = r.getrandbits(32)
    tail = pystub(c, 0, ret=tail_ret, side=lambda emu, k: emu.calllog.append(('tail', emu.reg('ecx'))))
    self = obj(c, 0x240, {0x110: end, 0x214: tail})
    hook_rec(c, 0x43e0f0, 0, this=True, pop=0,
        side=lambda emu, k: emu.calllog.append(('helper', emu.reg('ecx'))))
    return [self]


S(0x45b970, 'GUESS dispatch collection lifecycle callbacks', 'thiscall', None,
  ret='eax', gen=gen, note='batch62082')

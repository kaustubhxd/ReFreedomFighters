import struct
from pilot import S, F
from recruits_util import obj, rnd, sysobj, clear_hooks, pystub


def _bits(v):
    return struct.unpack('<I', struct.pack('<f', float(v)))[0]


def gen(c):
    clear_hooks(c)
    e, r = c.emu, c.rng
    inp = r.uniform(0.0, 20.0)
    first = r.uniform(0.0, 20.0)
    mode = r.randrange(4)
    early = mode != 0
    first_ret = inp if mode == 1 else (max(inp + 0.5, first) if early else min(inp, first))
    v_c = pystub(c, 1, ret=0, pop=4, this=True, st0=first_ret)

    count = r.randint(1, 4)
    items = []
    for _ in range(count + 1):
        item = obj(c, 0x20, {})
        e.w32(item + 8, _bits(r.uniform(0.1, 2.0)))
        items.append(item)
    begin = pystub(c, 1, ret=0, pop=4, this=True, nullflag=(0,),
                   side=lambda emu, k: emu.w32(emu.arg32(0), 0))
    nxt = pystub(c, 1, ret=lambda emu, k: items[k] if k < len(items) else 0,
                 pop=4, this=True, nullflag=(0,))
    length = pystub(c, 0, ret=count, pop=0, this=True)
    collection = obj(c, 0x80, {0x14: length, 0x4c: begin, 0x64: nxt})

    me = rnd(c, 0x40)
    vt = e.alloc(0x10, 4)
    e.w32(vt + 0xc, v_c)
    e.w32(me, vt)
    e.w32(me + 4, r.getrandbits(32) if early else 0)
    e.w32(me + 8, _bits(r.uniform(0.1, 4.0)))
    e.w32(me + 0xc, r.getrandbits(32))
    e.w32(me + 0x10, _bits(r.uniform(0.0, 1000.0)))
    e.w32(me + 0x14, collection)

    tick = r.randint(0, 10000)
    random_value = r.uniform(0.05, 1.0)
    so = sysobj(c, rand=random_value)
    e.w32(so + 0x40, tick)
    return [me, F(inp)]


S(0x483860, 'GUESS_accumulate_timed_float_items', 'thiscall', None,
  ret='eax', gen=gen, note='batch102010')

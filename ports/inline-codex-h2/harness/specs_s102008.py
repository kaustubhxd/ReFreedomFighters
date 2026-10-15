import random
import struct
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _fbits(x):
    return struct.unpack('<I', struct.pack('<f', float(x)))[0]


def gen(c):
    clear_hooks(c)
    e, r = c.emu, c.rng
    owner = rnd(c, 0x2700)
    vector = [r.uniform(-20.0, 20.0) for _ in range(3)]
    for i, x in enumerate(vector):
        e.w32(owner + 0x25f1 + 4*i, _fbits(x))
    e.w32(owner + 0x260c, r.choice([0, 0, 1, 2]))
    e.w32(owner + 0x2614, r.choice([0, 1]))
    e.w32(owner + 0x2618, _fbits(r.uniform(0.0, 100.0)))
    e.w32(owner + 0x25dd, r.getrandbits(32))

    stream_data = [r.uniform(-20.0, 20.0) for _ in range(3)]
    def fill_vector(emu, k):
        p = emu.arg32(0)
        for i, x in enumerate(stream_data):
            emu.w32(p + 4*i, _fbits(x))
    slot84 = pystub(c, 1, ret=0, pop=4, this=True, nullflag=(0,), side=fill_vector)
    slot90 = pystub(c, 1, ret=r.getrandbits(32), pop=4, this=True, deref={0: 3})
    stream = obj(c, 0x100, {0x84: slot84, 0x90: slot90})
    e.w32(owner + 0x25d1, stream)

    result_vector = [r.uniform(-10.0, 10.0) for _ in range(3)]
    def fill_result(emu, k):
        p = emu.arg32(0)
        for i, x in enumerate(result_vector):
            emu.w32(p + 4*i, _fbits(x))
    owner_vt = e.alloc(0x310, 4)
    build = pystub(c, 2, ret=0, pop=8, this=True, nullflag=(0,), side=fill_result)
    e.w32(owner_vt + 0x308, build)
    e.w32(owner, owner_vt)

    write_words = [r.getrandbits(32) for _ in range(19)]
    def fill_record(emu, k):
        p = emu.reg('ecx')
        for i, x in enumerate(write_words):
            emu.w32(p + 4*i, x)
    hook_rec(c, 0x4de040, 1, ret=0, pop=4, this='mark', side=fill_record)

    hook_rec(c, 0x514890, 6, ret=0, pop=24, this=True,
             deref={1: 2, 2: 19, 3: 3})
    hook_rec(c, 0x633654, 0, ret=lambda emu, k: emu.reg('ecx'), pop=0)
    e.w32(0x6f5630, r.getrandbits(32))
    e.w32(0x7003b0, pystub(c, 0, ret=r.getrandbits(32), pop=0))
    return [owner]


S(0x521db0, 'GUESS_compare_transformed_vector_distance', 'thiscall', None,
  ret=None, gen=gen, note='batch102008')

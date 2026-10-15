"""specs_s50015.py - u3 Haiku batch 50015, tier H. 0x493820: bitset hash table insertion with linear probing.
Creates mock object with vtable stubs for hash/probe/equality operations; hooks helper functions."""
import struct
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _g493820(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    # Create mock hash table
    capacity = r.choice([8, 16, 32, 64])

    # Create bitsets
    nwords = (capacity + 31) // 32
    bitsets = rnd(c, nwords * 4)

    # Create data array
    data = rnd(c, capacity * 8)

    # Slot 0x10 returns the two words used as the hash input and probe step seed.
    def make_key(em, k):
        src, out_key, out_step = em.arg32(0), em.arg32(1), em.arg32(2)
        em.w32(out_key, em.r32(src))
        em.w32(out_step, em.r32(src + 4))

    # Create vtable with stubs
    vtable_stubs = {
        0x10: pystub(c, 3, this=True, pop=12, side=make_key, stackmark=(1, 2)),
        # true means this key matches the occupied record; false probes onward
        0x14: pystub(c, 2, this=True, ret=lambda em, k: r.choice([0, 0, 0, 1])),
    }

    htable = obj(c, 0x40, vtable_stubs, nslots=0x20 // 4)

    e.w32(htable + 4, bitsets)
    e.w32(htable + 8, capacity)
    e.w32(htable + 0x10, 0)
    e.w32(htable + 0x14, 0)
    e.w32(htable + 0x18, data)
    e.wbytes(htable + 0x1c, struct.pack('<f', 0.0))

    # Create test args
    arg1 = rnd(c, 8)
    arg2 = r.getrandbits(32)
    arg3 = r.choice([0, 1])

    return [htable, arg1, arg2, arg3]


S(0x493820, 'GUESS hash table insert with linear probing', 'thiscall', None, ret='al', gen=_g493820, note='batch50015')

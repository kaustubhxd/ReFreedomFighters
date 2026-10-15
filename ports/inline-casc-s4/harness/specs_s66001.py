"""specs_s66001.py - cascade s4 batch 66001: 0x5e93f0 (deque erase)."""
from pilot import S
from recruits_util import rnd, clear_hooks


def _g5e93f0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    # Set up a simple deque-like structure at ecx
    # ecx + 0x48 = count (number of elements)
    # ecx + 0x4c = pointer to array data

    t = rnd(c, 0x100)

    # Create array with count elements
    count = r.randint(1, 5)
    e.w32(t + 0x48, count)

    # Allocate array data
    arr_data = e.alloc(count * 8 + 16, 8)  # Extra space for safety
    e.w32(t + 0x4c, arr_data)

    # Fill array with test values
    for i in range(count):
        val = r.choice([0, 1, 2, r.getrandbits(32)])
        e.w32(arr_data + i * 8, val)
        e.w32(arr_data + i * 8 + 4, r.getrandbits(32))

    # Choose erase mode: flag = 1 (erase zero) or flag = 0 (erase by value)
    flag = r.choice([0, 1])
    if flag:
        erase_val = 0  # Ignored when flag=1
    else:
        erase_val = r.choice([0, 1, 2, r.getrandbits(32)])

    return [t, flag, erase_val]


S(0x5e93f0, 'GUESS deque erase operation', 'stdcall', None, ret=None, gen=_g5e93f0, note='batch66001')

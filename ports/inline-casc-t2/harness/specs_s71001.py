"""specs_s71001.py - t2 (Haiku) batch 71001: 0x526360. Callees (0x516620) and vtable hooks."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub
import struct


def _g526360(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    so = sysobj(c)

    # Create test object with the structure expected by the function
    me = rnd(c, 0x900)

    # Fill in the counts
    count1 = r.randint(0, 3)
    count2 = r.randint(0, 3)
    e.w32(me + 0x8c, count1)
    e.w32(me + 0x90, count2)

    # Fill in structure data for first loop
    base1 = me + 0xbd
    cur1 = me + 0x7d1
    for i in range(5):  # fill slots
        f0 = r.choice([0.0, 1.0, -1.0, r.uniform(-5, 5)])
        f1 = r.choice([0.0, 1.0, -1.0, r.uniform(-5, 5)])
        f2 = r.choice([0.0, 1.0, -1.0, r.uniform(-5, 5)])
        e.wbytes(cur1 - 8, struct.pack('<f', f0))
        e.wbytes(cur1 - 4, struct.pack('<f', f1))
        e.wbytes(cur1, struct.pack('<f', f2))
        cur1 += 0x163

    # Fill in structure data for second loop
    base2 = me + 0x435
    cur2 = me + 0xd5d
    for i in range(5):  # fill slots
        f0 = r.choice([0.0, 1.0, -1.0, r.uniform(-5, 5)])
        f1 = r.choice([0.0, 1.0, -1.0, r.uniform(-5, 5)])
        f2 = r.choice([0.0, 1.0, -1.0, r.uniform(-5, 5)])
        e.wbytes(cur2 - 8, struct.pack('<f', f0))
        e.wbytes(cur2 - 4, struct.pack('<f', f1))
        e.wbytes(cur2, struct.pack('<f', f2))
        cur2 += 0x133

    # Hook 0x516620: just log it
    hook_rec(c, 0x516620, 1, pop=0)

    # Set engine object with vtable at slot 0x9b
    vtable = rnd(c, 0x100)
    # Install vtable hook at slot 0x84
    e.w32(vtable + 0x84, e.stub_fn('vcall_0x84', lambda emu, k: None))
    e.w32(so + 0x9b, vtable)

    # Set assert hook
    def assert_hook(emu, k):
        emu.calllog.append(('assert',))
        emu.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert', assert_hook))

    return [me]


S(0x526360, 'GUESS loop float processing', 'thiscall', None, ret=None, gen=_g526360, note='batch71001')

"""specs_s4120.py - unclaimed-41 batch 20 (slice 13): 0x46ffd0 ZItem::PlaySound(unsigned int) (thiscall, one stack argument, ret 4).

The item (this) has vtable slots +0x2c8 (two stack args, checksum), +0x94 (two stack args, checksum), +0x2f4 (a sequence stub:
calls return rets in order; no pop). The sequence is [t, p, r] when t != 0 (sites A, B, C), [0, r] when t == 0 (sites A, C).
p is an object whose slot +0x20 returns q (checksum, no args); q has slot +0x94 (two stack args). The render manager (0x70039c)
points at rm; rm+0x9b is object o, whose vtable slot +0x4c takes one argument (checksum). 0x43ec00 (five stack args, ecx = b)
is a checksum stub (GUESS). Stack-local addresses (&loc34, &loc10, and &loc34/&loc10 as the 0x43ec00 arguments 1 and 2) are
left out of the checksum. The hook is not used. Faulting cases must be 0 (JSON)."""
import struct
from pilot import S
import helper_stubs as hs
import serial_stubs as ss

P = lambda v: struct.pack('<I', v & 0xffffffff)


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _vt(c, slots):
    vt = c.emu.alloc(0x400, 4)
    for off, st in slots.items():
        c.emu.w32(vt + off, st)
    return vt


def _seqp(c, rets):
    """Returns the next (value, pop) pair of rets on each call (wraps after eight). pop is 0 (plain ret) or 4 (the stub pops its
    one stack argument). The original's stack discipline needs that: the site that pushes an argument (site C) is balanced by the
    callee, the two sites with no argument (A, B) are not. One slot cannot be both, so the pop count follows the call number."""
    rets = list(rets)[:8]
    rets = rets + [rets[-1]] * (8 - len(rets))
    tab = c.emu.alloc(32, 4)
    popt = c.emu.alloc(32, 4)
    c.emu.wbytes(tab, b''.join(P(v) for v, _ in rets))
    c.emu.wbytes(popt, b''.join(P(p) for _, p in rets))
    cnt = c.emu.alloc(4, 4)
    c.emu.w32(cnt, 0)
    acc = c.emu.alloc(4, 4)                      # checksum of the stack argument read on the pop path (site C)
    c.emu.w32(acc, 0)
    b = (b'\x8b\x0d' + P(cnt)                 # mov ecx, [cnt]
         + b'\x83\xe1\x07'                    # and ecx, 7
         + b'\xff\x05' + P(cnt)               # inc dword [cnt]
         + b'\x8b\x04\x8d' + P(tab)           # mov eax, [tab + ecx*4]
         + b'\x8b\x14\x8d' + P(popt)          # mov edx, [popt + ecx*4]
         + b'\x85\xd2'                        # test edx, edx
         + b'\x75\x01'                        # jnz +1 (over the ret below)
         + b'\xc3'                            # ret (no pop)
         + b'\x5a'                            # pop edx (return address)
         + b'\x8b\x0c\x24'                    # mov ecx, [esp] (the stack argument)
         + b'\x01\x0d' + P(acc)               # add [acc], ecx
         + b'\x83\xc4\x04'                    # add esp, 4 (the stack argument)
         + b'\xff\xe2')                       # jmp edx (return with the argument popped)
    return ss.code(c, b)


def _layout(c):
    # q: object with slot 0x94 (two args, checksum, leaves stack locals out)
    s94q, _, _ = hs.stub(c, 2, ecx=True, edx=False, mask=[], cleanup=True, ret=0)
    q = _rnd(c, 0x40)
    c.emu.w32(q, _vt(c, {0x94: s94q}))

    # p: object with slot 0x20 that returns q
    s20, _, _ = hs.stub(c, 0, ecx=True, edx=False, ret=q)
    p = _rnd(c, 0x40)
    c.emu.w32(p, _vt(c, {0x20: s20}))

    # the item, with the sequenced 0x2f4 slot. t is random; the sequence depends on t.
    t_nonzero = c.rng.random() < 0.5
    t = c.rng.getrandbits(32) | 1 if t_nonzero else 0
    r = c.rng.getrandbits(32)
    rets = [(t, 0), (p, 0), (r, 4)] if t_nonzero else [(0, 0), (r, 4)]
    s2f4 = _seqp(c, rets)
    s2c8, _, _ = hs.stub(c, 2, ecx=True, edx=False, mask=[], cleanup=True, ret=0)
    s94, _, _ = hs.stub(c, 2, ecx=True, edx=False, mask=[], cleanup=True, ret=0)
    this = _rnd(c, 0x100)
    c.emu.w32(this, _vt(c, {0x2f4: s2f4, 0x2c8: s2c8, 0x94: s94}))

    # 0x43ec00 (GUESS), five stack args; arguments 1 and 2 are stack locals (left out), ecx = b (not in the checksum)
    s43, _, _ = hs.stub(c, 5, ecx=True, edx=False, mask=[3, 4, 5], cleanup=True, ret=0)
    ss.patch(c, 0x43ec00, s43)

    # rm -> o; o's vtable slot +0x4c takes one argument (r) and returns a checksum-stub value
    s4c, _, _ = hs.stub(c, 1, ecx=True, edx=False, cleanup=True, ret=c.rng.getrandbits(32))
    o = _rnd(c, 0x40)
    c.emu.w32(o, _vt(c, {0x4c: s4c}))
    rm = _rnd(c, 0x200)
    c.emu.w32(rm + 0x9b, o)
    c.emu.w32(0x70039c, rm)
    c.emu._image_dirty = True

    sound = c.rng.choice([0, 1, c.rng.getrandbits(32)]) if c.rng.random() < 0.1 else c.rng.getrandbits(32)
    return [this, sound]


S(0x46ffd0, 'ZItem::PlaySound(unsigned int) (vtable)', 'thiscall', None, ret=None, gen=_layout,
  note='unclaimed-41 batch 20; the 0x2f4 slot is a sequence stub (sites A, B, C) with plain ret; 0x43ec00 and the 0x2c8, 0x94, 0x4c, 0x20 slots are checksum stubs (GUESS); the /GS cookie check is not reproduced')

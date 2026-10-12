"""specs_s239.py - area 59, batch239 (src/batch239.cpp): 0x4e3ae0, recursive cell traversal.

Layout the spec builds: a node is 16-bit fields (flags, count at +2, item index at +4). Items are 16-byte records with six
16-bit bounds. Entries are 6-byte records whose first word carries the end bit 0x8000. The callback (state+4) is a recorder:
it counts calls and stores ecx and edx. The depth counter starts at 0; the cell half-size halves per level, so recursion
terminates. Item indices and bounds are kept small so every address stays inside its buffer.
"""
from pilot import S
import serial_stubs as ss
from helpers22 import _rnd, _flush_heap_code, jmp_patch


BOUNDS = [0, 0x40, 0x80, 0x100, 0x180, 0x200, 0x400]   # small set so the boundary tests see equal values


def _words(c, buf, n, lo, hi):
    for i in range(n):
        c.emu.w16(buf + 2 * i, c.rng.randrange(lo, hi))


def _g_4e3ae0(c):
    state = _rnd(c, 0x100)
    items = _rnd(c, 16 * 8)
    for i in range(8):
        base = items + 16 * i
        for k in range(6):
            c.emu.w16(base + 4 + 2 * k, c.rng.choice(BOUNDS))
    ents = _rnd(c, 6 * 40)
    for i in range(40):
        # word0: bits 0..2 = the octant, bits 3..4 = an item count 0..3 (entries are read as nodes), bit 15 = end
        c.emu.w16(ents + 6 * i, c.rng.randrange(0, 8) | (c.rng.randrange(0, 4) << 3) | (0x8000 if c.rng.random() < 0.6 else 0))
        c.emu.w16(ents + 6 * i + 2, c.rng.randrange(0, 4))
        c.emu.w16(ents + 6 * i + 4, c.rng.randrange(0, 8))
    c.emu.w16(ents + 6 * 39, 0x8000 | c.rng.randrange(0, 8))   # the last entry always ends the walk
    c.emu.w32(state + 0x10, items)
    c.emu.w32(state + 0xc, ents)
    c.emu.w32(state + 0x2c, c.rng.choice([0, 8, 9]))
    for off in (0x50, 0x54, 0x58):
        c.emu.w32(state + off, c.rng.choice(BOUNDS))
    cnt = c.emu.alloc(4, 4)
    ecx_s = c.emu.alloc(4, 4)
    edx_s = c.emu.alloc(4, 4)
    for a in (cnt, ecx_s, edx_s):
        c.emu.w32(a, 0)
    code = (b'\xff\x05' + ss.P(cnt)                  # inc dword [cnt]
            + b'\x89\x0d' + ss.P(ecx_s)              # mov [ecx_s], ecx
            + b'\x89\x15' + ss.P(edx_s)              # mov [edx_s], edx
            + b'\xc3')
    c.emu.w32(state + 4, ss.code(c, code))
    node = _rnd(c, 0x20)
    c.emu.w16(node, c.rng.randrange(0, 0x10000))
    c.emu.w16(node + 2, c.rng.randrange(0, 4))
    c.emu.w16(node + 4, c.rng.randrange(0, 8))
    c.emu.w16(node, c.rng.randrange(0, 4) << 3)
    _flush_heap_code(c)
    c.emu.mu.ctl_flush_tb()
    # root centre: a small set of values (the boundary tests see equal values). A centre equal to the box makes the
    # recursion reach zero-size cells with equal coordinates, which recurses forever in the original too, so it is not used.
    return [node, state, c.rng.choice(BOUNDS), c.rng.choice(BOUNDS), c.rng.choice(BOUNDS)]


S(0x4e3ae0, 'cellTraverse (GUESS)', 'thiscall', None, ret=None, gen=_g_4e3ae0,
  note='batch239; recursive cell traversal; callback at state+4 recorded (count, ecx, edx)')

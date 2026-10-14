"""specs_s31094.py - batch 31094."""
import struct
from pilot import S
from pe_emu import REGS
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def r32(c):
    return c.rng.getrandbits(32)


def st(c, n, ret=None, clob=False, pop=None, side2=None):
    j = r32(c)

    def side(emu, k):
        if side2:
            side2(emu, k)
        if clob:
            emu.mu.reg_write(REGS['ecx'], j)
    return pystub(c, n, ret=r32(c) if ret is None else ret, pop=pop, this=True, side=side if (clob or side2) else None)


def hk(c, addr, n, pop=0, ret=None, clob=True):
    side = None
    if clob:
        j = r32(c)
        side = lambda emu, k: emu.mu.reg_write(REGS['ecx'], j)
    hook_rec(c, addr, n, ret=r32(c) if ret is None else ret, pop=pop, this=True, side=side)


def g487550(c):
    clear_hooks(c)
    r = c.rng
    sysobj(c, table_slots={0x4c: st(c, 1, ret=r.choice([0, 1, r32(c)]))})
    write = r.random() < 0.5
    val = r.choice([0, 0, r32(c)])

    def put(emu, k):
        if write:
            emu.w32(emu.arg32(1), val)
    a = obj(c, 0x140, {0x128: st(c, 3, side2=put)})
    me = rnd(c, 0x20)
    return [me, a]


def g4f7900(c):
    clear_hooks(c)
    r = c.rng
    me = obj(c, 0xb0, {0x388: st(c, 0, ret=r.choice([0, 1, 2, 3, 5, -1 & 0xffffffff, 100]), clob=True)})
    sub = obj(c, 0x100, {0xbc: st(c, 1)})
    c.emu.w32(me + 0x8f, 0 if r.random() < 0.15 else sub)
    c.emu.w32(me + 0x93, r.choice([0, 1, r32(c)]))
    fl = r.choice([0.0, 1.0, 2.0, 2.5, -1.0, 3.9, 100.0, 1e20])
    c.emu.wbytes(me + 0x9f, struct.pack('<f', fl))
    return [me]


def g514b90(c):
    clear_hooks(c)
    r = c.rng
    hk(c, 0x512070, 0)
    hk(c, 0x45c510, 1, pop=0, clob=False)
    hk(c, 0x4690b0, 2, pop=0, clob=False)
    return [rnd(c, 0x40), r.choice([0, 1, 2, 3, 4, 5, 7, r32(c)])]


S(0x487550, 'GUESS table slot 0x4c(this+6) into local, arg slot 0x128, nonzero test', 'thiscall', None, ret='al', gen=g487550, note='batch31094')
S(0x4f7900, 'GUESS slot 0x388 vs float limit decides flag for member slot 0xbc', 'thiscall', None, ret='eax', gen=g4f7900, note='batch31094')
S(0x514b90, 'GUESS 512070 then flag bits choose 45c510 or 4690b0', 'thiscall', None, ret='eax', gen=g514b90, note='batch31094')

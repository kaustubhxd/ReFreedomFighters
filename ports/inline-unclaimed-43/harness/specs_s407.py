"""specs_s407.py - gap band parked row 0x4cfce0 (thiscall, three stack arguments, ret 0xc; exe code, not hooked) and its
forwarder 0x41ef30 (thiscall, same arguments, tail call). The object is 0x20000 bytes of random data with the fields the
function reads: dword +0x20f (old, sometimes -1), dword +0x8217 (S, 1..0x40 so the divisions are safe), and the three arguments
chosen so the early returns, the signed compare and the loop all run. The forwarder's object points to the inner block at +0x31."""
from pilot import S
import engine_stubs as E


def _draw(c):
    r = c.rng
    obj = E.zero_obj(c, 0x20000)
    c.emu.wbytes(obj, bytes(r.getrandbits(8) for _ in range(0x20000)))
    old = 0xffffffff if r.random() < 0.1 else r.randint(0, 0x2000)
    Sv = r.randint(1, 0x40)
    c.emu.w32(obj + 0x20f, old)
    c.emu.w32(obj + 0x8217, Sv)
    if r.random() < 0.8:
        a1 = (old + r.randint(0, Sv * 8192 + 0x100)) & 0xffffffff
    else:
        a1 = r.getrandbits(32)
    a2 = r.randint(0, 0x100000)
    a3 = r.getrandbits(32)
    return obj, [a1, a2, a3]


def _gen(c):
    obj, args = _draw(c)
    c.emu.mu.ctl_flush_tb()
    return [obj] + args


def _gen_fwd(c):
    obj, args = _draw(c)
    wrap = E.zero_obj(c, 0x40)
    c.emu.w32(wrap + 0x31, obj)
    c.emu.mu.ctl_flush_tb()
    return [wrap] + args


S(0x4cfce0, 'range bits in the allocator table (gap band parked) thiscall', 'thiscall', None, ret=None, gen=_gen,
  note='gap band parked row, exe code; ported from the disassembly (170 bytes)')
S(0x41ef30, 'forward to 0x4cfce0 via [this+0x31] (gap band parked) thiscall', 'thiscall', None, ret=None, gen=_gen_fwd,
  note='gap band parked row; forwards to exe 0x4cfce0')

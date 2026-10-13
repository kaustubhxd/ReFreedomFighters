"""specs_s2493.py - decomp area 24, batch 2493 (residue 3, smallest first).
0x4f3ab0 (GUESS, ZWINGROUP fade step): thiscall, void. Byte +0x68 and +0x69, float +0x6b, system dword +0x40, dword +0x64 as in the source.
FadeGroup 0x4f2240 is recorded (thiscall, two args, callee pops 8).
0x4d7130 (GUESS, path normaliser): fastcall (ecx = source string, edx = buffer), returns the buffer in eax. The source is a generated
string of letters, slashes and backslashes; the buffer is compared through the heap delta."""
import struct
from pilot import S
from recruits_util import rnd, pystub, obj, sysobj, clear_hooks, hook_rec


def _fade(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x4f2240, 2, this=True)
    so = sysobj(c)
    x = r.uniform(-30.0, 30.0)
    x32 = struct.unpack('<f', struct.pack('<f', x))[0]
    s = int(x32 * 1024.0)   # truncation, as cvttss2si
    # About a third of the cases sit exactly on the boundary (s == system dword), so the strict < is exercised.
    lim = s if r.random() < 0.33 else r.randint(-30000, 30000)
    e.w32(so + 0x40, lim & 0xffffffff)
    o = rnd(c, 0x100)
    e.wbytes(o + 0x68, bytes([r.getrandbits(8)]))
    e.wbytes(o + 0x69, bytes([r.getrandbits(8)]))
    e.w32(o + 0x64, r.getrandbits(32))
    e.w32(o + 0x6b, struct.unpack('<I', struct.pack('<f', x))[0])
    return [o]


def _norm(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    n = r.randint(0, 20)
    alphabet = b'abcXYZ/\\._-'
    s = bytes(r.choice(alphabet) for _ in range(n)) + b'\x00'
    src = e.alloc(len(s) + 4, 4)
    e.wbytes(src, s)
    dst = rnd(c, 0x40)
    return [src, dst]


S(0x4f3ab0, 'GUESS ZWINGROUP fade step', 'thiscall', None, ret=None, gen=_fade, note='batch2493')
S(0x4d7130, 'GUESS path normaliser', 'fastcall', None, ret='eax', gen=_norm, note='batch2493')

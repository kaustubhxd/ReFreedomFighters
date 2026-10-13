"""specs_s13006.py - fresh-13 batch 6: 0x5da2d0 CTVStudioCam::FrameUpdate. Thiscall, no args. 0x5da470 is a logged hook
returning a target object (or 0 in 10%); the target's vtbl+0x23c is a logged stub that records the four floats its
pointer argument points at. Mode +0x4c in {0,1,2,3,random}; +0x48 spans -0.5..2 (with 0, 1, 1.5236 edges and NaN);
dt = *(0x70039c)+0x48 in 0..0.2. The CRT sin import is the harness's default stub (same on both sides). Heap words are
floats (nan_heap)."""
from pilot import S
from fr13 import Log, loghook, logstub, vobj, rnd, clear_hooks, flush
import struct


def _f(x):
    return struct.unpack('<I', struct.pack('<f', x))[0]


def _gen(c):
    r = c.rng
    clear_hooks(c)
    log = Log(c, cap=8, width=8)
    tgt = vobj(c, 0x40, {0x23c: logstub(c, log, 1, 2, deref={0: 4})}) if r.random() < 0.9 else 0
    loghook(c, log, 0x5da470, 0, 1, ret=tgt)
    sysobj = rnd(c, 0x100)
    c.emu.wf32(sysobj + 0x48, r.uniform(0, 0.2) if r.random() < 0.9 else r.choice([0.0, 1.0, 4.0]))
    c.emu.w32(0x70039c, sysobj)
    me = rnd(c, 0x100)
    c.emu.w32(me + 0x4c, r.choice([0, 1, 1, 2, 2, 3, r.getrandbits(32)]))
    k = r.random()
    x = r.uniform(-0.5, 2.0) if k < 0.8 else r.choice([0.0, -0.0, 1.0, 1.5235987, 1.5235988, 0.9999, float('nan')])
    c.emu.wf32(me + 0x48, x)
    for off in range(0x66, 0x86, 4):
        c.emu.wf32(me + off, r.uniform(-2, 2))
    flush(c)
    return [me]


S(0x5da2d0, 'CTVStudioCam::FrameUpdate', 'thiscall', None, ret=None, gen=_gen, nan_heap=True,
  note='fresh13 batch13006; 0x5da470 hooked; target vtbl+0x23c logs the four floats')

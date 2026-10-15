"""specs_s75001.py - tier H slice 5. 0x51cf10: /GS function, SSE float loads, multiple vcalls and direct call."""
from pilot import S, EDGE_F
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec
import struct


def _fbits(r):
    k = r.random()
    if k < 0.15:
        v = r.choice(EDGE_F)
    elif k < 0.2:
        return r.getrandbits(32)
    else:
        v = r.uniform(-100, 100)
    return struct.unpack('<I', struct.pack('<f', v))[0]


def _g51cf10(c):
  clear_hooks(c)
  r = c.rng

  st_v36c = pystub(c, 0, this=True, ret=r.getrandbits(32))
  st_v88 = pystub(c, 1, this=True, ret=r.getrandbits(32))
  st_v7c = pystub(c, 2, this=True, ret=r.getrandbits(32))
  st_43e8e0 = pystub(c, 3, ret=r.getrandbits(32))

  self_obj = obj(c, 0x400, {
    0x36c: st_v36c,
    0x88: st_v88,
    0x7c: st_v7c
  }, nslots=0x140)

  for off in (0x276, 0x27a, 0x27e):
    c.emu.w32(self_obj + off, _fbits(r))

  hook_rec(c, 0x43e8e0, 3, ret=r.getrandbits(32))

  return [self_obj]


S(0x51cf10, 'GUESS /GS float loads', 'thiscall', None, ret=None, gen=_g51cf10, note='batch75001')

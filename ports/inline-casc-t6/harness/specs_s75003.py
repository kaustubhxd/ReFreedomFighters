"""specs_s75003.py - tier H slice 5. 0x5007e0: /GS with 3 args, engine table lookup. 0x51e470: SSE floats, comparisons, assert hook."""
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


def _g5007e0(c):
  clear_hooks(c)
  r = c.rng

  st_v18 = pystub(c, 1, this=True, ret=r.getrandbits(32))
  st_v58 = pystub(c, 0, this=True, ret=r.getrandbits(32) if r.random() < 0.5 else 0)
  st_v4c = pystub(c, 1, this=True, ret=r.getrandbits(32))
  st_v30 = pystub(c, 1, this=True, ret=r.getrandbits(32))

  p1_obj = obj(c, 0x100, {0x18: st_v18}, nslots=0x50)

  eng_obj = rnd(c, 0x100)
  table_obj = obj(c, 0x100, {0x58: st_v58, 0x4c: st_v4c}, nslots=0x50)
  c.emu.w32(eng_obj + 0x9b, table_obj)
  c.emu.w32(0x70039c, eng_obj)

  p2 = rnd(c, 0x40)
  p3 = rnd(c, 0x40)

  self_obj = obj(c, 0x40, {0x30: st_v30}, nslots=0x20)

  return [self_obj, p1_obj, p2, p3]


def _g51e470(c):
  clear_hooks(c)
  r = c.rng

  assert_stub = pystub(c, 0, ret=r.getrandbits(32))
  c.emu.w32(0x7003b0, assert_stub)

  self_obj = rnd(c, 0x600)

  if r.random() < 0.3:
    c.emu.w32(self_obj + 0x34a, 1)
  else:
    c.emu.w32(self_obj + 0x34a, 0)

    if r.random() < 0.4:
      c.emu.w32(self_obj + 0x469, r.randint(1, 5))
      c.emu.w32(self_obj + 0x597, _fbits(r))
    else:
      c.emu.w32(self_obj + 0x469, 0)

    c.emu.w32(self_obj + 0x236, _fbits(r))
    c.emu.w32(self_obj + 0x23a, _fbits(r))

  eng_obj = rnd(c, 0x100)
  target = obj(c, 0x200, {0x184: pystub(c, 8, this=True, pop=0, ret=r.getrandbits(32))}, nslots=0x80)
  st_v190 = pystub(c, 0, this=True, ret=target)
  eng_vt = obj(c, 0x100, {0x190: st_v190}, nslots=0x80)
  c.emu.w32(eng_obj, eng_vt)
  c.emu.w32(0x70039c, eng_obj)

  return [self_obj]


S(0x5007e0, 'GUESS engine table lookup', 'thiscall', None, ret=None, gen=_g5007e0, note='batch75003')
S(0x51e470, 'GUESS SSE float min ops', 'thiscall', None, ret=None, gen=_g51e470, note='batch75003')

"""specs_s75002.py - tier H slice 5. 0x45bb10: thiscall with 5 stack args, engine lookups, float args."""
from pilot import S, EDGE_F, F
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec
import struct


def _fbits(r):
    k = r.random()
    if k < 0.15:
        v = r.choice(EDGE_F)
    elif k < 0.2:
        return r.getrandbits(32)
    else:
        v = r.uniform(-10, 10)
    return struct.unpack('<I', struct.pack('<f', v))[0]


def _g45bb10(c):
  clear_hooks(c)
  r = c.rng

  # Create stubs for vtable operations
  result_obj = obj(c, 0x80, {0x38: pystub(c, 2, this=True, ret=r.getrandbits(32)),
                             0x3c: pystub(c, 6, this=True, ret=r.getrandbits(32))}, nslots=0x20)
  st_v20 = pystub(c, 0, this=True, ret=result_obj)

  # Engine object with vtable
  eng_obj = rnd(c, 0x2000)
  inner = obj(c, 0x80, {0x20: st_v20}, nslots=0x20)
  c.emu.w32(eng_obj + 0x190f, inner)

  # Self object
  self_obj = rnd(c, 0x100)
  if r.random() < 0.5:
    c.emu.w32(self_obj + 0x44, 0xffffffff)
  else:
    c.emu.w32(self_obj + 0x44, r.randint(0, 100))

  store_ptr = rnd(c, 0x100)
  c.emu.w32(self_obj + 0x40, store_ptr)

  # Arguments
  p0 = rnd(c, 0x100)
  f1 = _fbits(r)
  f2 = _fbits(r)
  p1 = r.randint(0, 20)

  # Set up engine global
  c.emu.w32(0x70039c, eng_obj)

  # Hook direct call
  hook_rec(c, 0x45b620, 1, this=True, ret=r.randint(0, 10))

  return [self_obj, p0, p1, F(struct.unpack('<f', struct.pack('<I', f1))[0]),
          F(struct.unpack('<f', struct.pack('<I', f2))[0]), r.getrandbits(32)]


S(0x45bb10, 'GUESS engine init and call', 'thiscall', None, ret=None, gen=_g45bb10, note='batch75002')

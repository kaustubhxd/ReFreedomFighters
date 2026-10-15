"""specs_s75000.py - tier H slice 5. 0x49a560: thiscall with arg that has count at offset 0; loops calling vtable slots 0xc on arg, 0x14/0x40/0x50 on this."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec


def _g49a560(c):
  clear_hooks(c)
  r = c.rng

  count = r.randint(0, 8)

  st_vc = pystub(c, 0, this=True, ret=r.getrandbits(32))
  st_v14 = pystub(c, 1, this=True, ret=r.getrandbits(32))
  st_v40 = pystub(c, 1, this=True, ret=r.getrandbits(32))
  st_v50 = pystub(c, 1, this=True, ret=r.getrandbits(32))
  st_v98 = pystub(c, 4, this=True, ret=r.getrandbits(32))

  self_obj = obj(c, 0x100, {
    0x14: st_v14,
    0x40: st_v40,
    0x50: st_v50
  }, nslots=0x60)

  arg_vt = obj(c, 0x100, {
    0xc: st_vc,
    0x98: st_v98
  }, nslots=0x60)

  arg_ptr = rnd(c, 0x40)
  c.emu.w32(arg_ptr, count)
  c.emu.w32(arg_ptr + 4, arg_vt)

  return [self_obj, arg_ptr]


S(0x49a560, 'GUESS loop arg by count', 'thiscall', None, ret=None, gen=_g49a560, note='batch75000')

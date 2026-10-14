from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub

def gen_4c62c0(c):
  clear_hooks(c)
  this = obj(c, 0x100, {})
  c.emu.w16(this + 0x48, rnd(c, 65536))
  c.emu.w32(this + 0x4a, rnd(c, 100000))
  param1 = rnd(c, 65536)
  output = obj(c, 0x20, {})
  return [this, param1, output]

def gen_5ad2b0(c):
  clear_hooks(c)
  this = obj(c, 0x100, {})
  param = obj(c, 0x20, {})
  c.emu.w8(param + 0, rnd(c, 255))
  c.emu.w8(param + 1, rnd(c, 255))
  c.emu.w8(param + 2, rnd(c, 255))
  c.emu.w8(param + 3, rnd(c, 255))
  return [this, param]

def gen_5df720(c):
  clear_hooks(c)
  this = obj(c, 0x100, {})
  param1 = rnd(c, 100000)
  param2 = rnd(c, 100000)
  param3 = rnd(c, 100000)
  return [this, param1, param2, param3]

S(0x4c62c0, 'func_4c62c0', 'thiscall', None, ret=None, gen=gen_4c62c0)
S(0x5ad2b0, 'func_5ad2b0', 'thiscall', None, ret=None, gen=gen_5ad2b0)
S(0x5df720, 'func_5df720', 'thiscall', None, ret=None, gen=gen_5df720)

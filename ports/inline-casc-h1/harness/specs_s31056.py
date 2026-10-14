from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub

def gen_5aedb0(c):
  clear_hooks(c)
  this = obj(c, 0x100, {})
  return [this]

def gen_64fc20(c):
  clear_hooks(c)
  this = obj(c, 0x100, {})
  c.emu.w32(this + 0x60, rnd(c, 100000))
  c.emu.w32(this + 0x64, rnd(c, 100000))
  output = obj(c, 0x40, {})
  return [this, output]

def gen_410100(c):
  clear_hooks(c)
  param = obj(c, 0x20, {})
  inner = obj(c, 0x40, {})
  c.emu.w8(inner + 4, rnd(c, 255))
  c.emu.w32(param + 0, inner)
  return [param]

S(0x5aedb0, 'func_5aedb0', 'thiscall', None, ret=None, gen=gen_5aedb0)
S(0x64fc20, 'func_64fc20', 'thiscall', None, ret=None, gen=gen_64fc20)
S(0x410100, 'func_410100', 'cdecl', None, ret='eax', gen=gen_410100)

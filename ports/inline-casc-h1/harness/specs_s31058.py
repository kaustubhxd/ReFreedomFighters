from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub

def gen_4eb060(c):
  clear_hooks(c)
  this = obj(c, 0x100, {})
  param1 = rnd(c, 100000)
  param2 = rnd(c, 100000)
  return [this, param1, param2]

def gen_5c7ed0(c):
  clear_hooks(c)
  this = obj(c, 0x100, {})
  return [this]

def gen_62c9b0(c):
  clear_hooks(c)
  param = obj(c, 0x40, {})
  return [param]

def gen_5df6c0(c):
  clear_hooks(c)
  this = obj(c, 0x100, {})
  param1 = rnd(c, 100000)
  param2 = rnd(c, 100000)
  param3 = rnd(c, 100000)
  return [this, param1, param2, param3]

S(0x4eb060, 'func_4eb060', 'thiscall', None, ret=None, gen=gen_4eb060)
S(0x5c7ed0, 'func_5c7ed0', 'thiscall', None, ret=None, gen=gen_5c7ed0)
S(0x62c9b0, 'func_62c9b0', 'cdecl', None, ret=None, gen=gen_62c9b0)
S(0x5df6c0, 'func_5df6c0', 'thiscall', None, ret=None, gen=gen_5df6c0)

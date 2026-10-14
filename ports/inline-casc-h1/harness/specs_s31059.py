from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub

def gen_465870(c):
  clear_hooks(c)
  param = rnd(c, 100)
  return [param]

def gen_63eab0(c):
  clear_hooks(c)
  this = obj(c, 0x100, {})
  arr = obj(c, 0x4000, {})
  c.emu.w32(this + 0x68, arr)
  idx = rnd(c, 100) & 0xfff
  c.emu.w32(arr + idx*4, rnd(c, 100000))
  return [this, rnd(c, 100000)]

def gen_651010(c):
  clear_hooks(c)
  this = obj(c, 0x100, {})
  param1 = rnd(c, 100000)
  param2 = rnd(c, 100000)
  return [this, param1, param2]

S(0x465870, 'func_465870', 'stdcall', None, ret='eax', gen=gen_465870)
S(0x63eab0, 'func_63eab0', 'thiscall', None, ret='eax', gen=gen_63eab0)
S(0x651010, 'func_651010', 'thiscall', None, ret=None, gen=gen_651010)

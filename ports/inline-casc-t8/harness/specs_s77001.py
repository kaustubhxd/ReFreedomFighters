"""specs_s77001.py - t8 batch 77001: 0x595100 (setup/config with hooked calls)"""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _g595100(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    
    eng = sysobj(c)
    
    # Hook engine vtable slot 0x138 to return a valid object
    def ret_obj(em, k):
        obj_addr = em.alloc(0x100, 4)
        em.w32(obj_addr, em.alloc(0x40, 4))  # vtable
        em.ret(eax=obj_addr)
    
    def ret_none(em, k):
        em.ret()
    
    def ret_noop(em, k):
        pass
    
    ev = obj(c, 0x100, {
        0x138: pystub(c, 0, this=True, side=ret_obj),
        0x88: pystub(c, 1, this=True, side=ret_none),
        0x20: pystub(c, 2, pop=0, side=ret_none),
        0x2c: pystub(c, 3, pop=0, side=ret_none),
    })
    e.w32(eng + 0x9b, ev)
    
    # Hook external functions to do nothing
    hook_rec(c, 0x5aee60, 1, pop=0, side=ret_noop)
    hook_rec(c, 0x5afed0, 2, this=True, side=ret_noop)
    hook_rec(c, 0x5af8f0, 3, this=True, side=ret_noop)
    hook_rec(c, 0x5af990, 4, this=True, side=ret_noop)
    
    # Assert hook
    e.w32(0x7003b0, e.stub_fn('assert', lambda em, k: em.ret(eax=r.getrandbits(32))))
    
    # Set engine field  
    e.w32(eng + 0x1b5d, r.choice([0, 1]))
    
    # Create test object with field at 0x54
    me = rnd(c, 0x1000)
    field54 = obj(c, 0x10, {0: 0, 1: r.choice([1, 2, 3])})
    e.w32(me + 0x54, field54)
    
    return [me]


S(0x595100, 'GUESS engine setup with hooked calls', 'thiscall', None, ret=None, gen=_g595100, note='batch77001')

"""specs_s77002.py - t8 batch 77002: 0x4f2a30 (minimal test)"""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _g4f2a30(c):
    clear_hooks(c)
    
    # Minimal spec - just hook assert and return random objects
    def ret_noop(em, k):
        pass
    
    e = c.emu
    r = c.rng
    
    # Hook assert hook
    e.w32(0x7003b0, e.stub_fn('assert', lambda em, k: em.ret(eax=r.getrandbits(32))))
    
    # Return a minimal object
    return [rnd(c, 0x100)]


S(0x4f2a30, 'GUESS minimal stub test', 'thiscall', None, ret=None, gen=_g4f2a30, note='batch77002')

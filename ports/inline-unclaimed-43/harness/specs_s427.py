"""specs_s427.py - residue 2 row 0x5f9260 (thiscall, no arguments; stack canary and vtable slot call with assert hook).
Canary setup: xor [ebp-4] with [0x6f5630]. Call 0x5fa630 (GUESS, hooked by address, returns a pointer).
Call slot 0x14 of the pointer's vtable with arguments ([this+0xac6], [this+0x82], 0x6b8e80, local buffer, pointer).
Check assert hook at 0x7003b0 (if non-null, call it with ECX = this). Validate canary, call 0x633654 (stack check, hooked)."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S
import engine_stubs as E
import pe_emu

SHARED = {'ptr': 0, 'canary': 0, 'hook_addr': 0}


def _vt(c, name, slots_spec, n=0x40):
    slots = {}
    for i in range(n // 4):
        slots[4 * i] = (lambda e, rr: e.ret(eax=0, argbytes=0))
    slots.update(slots_spec)
    return c.emu.fake_vtable(name, n // 4, slots)


def _setup(c):
    def h5fa6(em, rr):
        em.calllog.append(('ext_5fa630', 0, em.reg('ecx') & 0xffffffff, ()))
        em.ret(eax=SHARED['ptr'], argbytes=0)
    c.emu.hook(0x5fa630, h5fa6)

    def h633(em, rr):
        em.calllog.append(('ext_633654', 0, 0, ()))
        em.ret(eax=0, argbytes=0)
    c.emu.hook(0x633654, h633)

    def h_hook(em, rr):
        em.calllog.append(('assert_hook', 0, em.reg('ecx') & 0xffffffff, ()))
        em.ret(eax=0, argbytes=0)
    hook_addr = c.emu.alloc(4, 4)
    c.emu.hook(hook_addr, h_hook)
    SHARED['hook_addr'] = hook_addr


def _gen(c):
    r = c.rng
    SHARED['canary'] = r.getrandbits(32)

    def h14(e, rr):
        e.calllog.append(('slot_0x14', 0x14, e.reg('ecx') & 0xffffffff,
                          tuple(e.arg32(k) for k in range(5))))
        e.ret(eax=0, argbytes=0x14)

    # Create the vtable
    vtable = _vt(c, 'VOBJ', {0x14: h14})

    # Create a container that points to the vtable
    container = E.zero_obj(c, 0x100)
    c.emu.w32(container, vtable)

    SHARED['ptr'] = container

    E.set_global(c, 0x6f5630, SHARED['canary'])
    E.set_global(c, 0x7003b0, SHARED['hook_addr'])

    o = E.zero_obj(c, 0x2000)
    for i in range(0x2000 // 4):
        c.emu.w32(o + 4 * i, r.getrandbits(32))
    c.emu.mu.ctl_flush_tb()
    return [o, r.getrandbits(32)]


S(0x5f9260, 'stack check with hook (residue 2) thiscall', 'thiscall', None, ret=None, gen=_gen, setup=_setup,
  note='residue 2 batch 427; 0x5fa630 and 0x633654 hooked (GUESS); assert hook hooked and non-NULL; vtable slot 0x14 mocked')

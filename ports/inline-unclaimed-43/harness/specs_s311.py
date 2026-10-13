"""specs_s311.py - unclaimed-43 batch 311: ZActor scalar deleting destructor (0x4775e0), thiscall, one stack argument, ret 4.
The base destructor (0x477480) runs as original code on a zeroed object. The member and sub-base destructors (0x4cbec0, 0x471f60) are hooked and logged; the three delete entries are hooked and logged
(the fake heap has no free): 0x634273 (__builtin_delete), 0x45c510 (delete wrapper), 0x4690b0 (sized delete); as in unclaimed-42.
flags covers bit 0 (delete or not) and bit 2 (sized or not)."""
from pilot import S
import engine_stubs as E
import pe_emu


def _nostack(x):
    return 'stack' if pe_emu.STACK_TOP - pe_emu.STACK_SIZE <= x < pe_emu.STACK_TOP else x


def _vtable(c, name, nslots, argwords):
    """logging vtable (thiscall; each slot logs its stack arguments and returns 0)."""
    slots = {}
    for i in range(nslots):
        off = 4 * i

        def h(e, r, off=off):
            n = argwords.get(off, 0)
            args = [e.arg32(k) for k in range(n)]
            e.calllog.append((name, off, e.reg('ecx'), tuple(_nostack(x) for x in args)))
            e.ret(eax=0, argbytes=4 * n)
        slots[off] = h
    return c.emu.fake_vtable(name, nslots, slots)


def _hook_deletes(c):
    c.emu.hook(0x634273, lambda em, r: (em.calllog.append(('builtin_delete', 0, 0, (em.arg32(0),))), em.ret(eax=0, argbytes=0)))
    c.emu.hook(0x45c510, lambda em, r: (em.calllog.append(('delete_wrap', 0, 0, (em.arg32(0),))), em.ret(eax=0, argbytes=0)))
    c.emu.hook(0x4690b0, lambda em, r: (em.calllog.append(('delete_sized', 0, 0, (em.arg32(0), em.arg32(1)))), em.ret(eax=0, argbytes=0)))
    # member and sub-base destructors of the base destructor: logged, not run
    c.emu.hook(0x4cbec0, lambda em, r: (em.calllog.append(('mystr_dtor', 0, em.reg('ecx'), ())), em.ret(eax=0, argbytes=0)))
    c.emu.hook(0x471f60, lambda em, r: (em.calllog.append(('subbase_dtor', 0, em.reg('ecx'), ())), em.ret(eax=0, argbytes=0)))


def _gen(c):
    # the engine object: the destructor calls its slot 0x1a8 unconditionally
    eng = E.zero_obj(c, 0x400)
    c.emu.w32(eng, _vtable(c, 'ZENGINE', 0x1a8 // 4 + 1, {0x1a8: 1}))
    E.set_global(c, 0x70039c, eng)
    o = E.zero_obj(c, 0x400)
    flags = c.rng.getrandbits(32)
    c.emu.mu.ctl_flush_tb()
    return [o, flags]


S(0x4775e0, 'ZActor::~ZActor scalar deleting (name-map demoted)', 'thiscall', None, ret='eax', gen=_gen,
  setup=_hook_deletes, note='unclaimed-43 batch 311 (core residue-02); base dtor 0x477480 original; deletes hooked')

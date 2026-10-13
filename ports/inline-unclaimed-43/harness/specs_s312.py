"""specs_s312.py - unclaimed-43 batch 312: ZFFActor::PerformDrop (0x5a1a60), thiscall, one stack argument, ret 4.
The engine (g_pSysInterface, 0x70039c) carries the flag dword at +0x1b5d (1 in 60% of cases). Its member at +0x9b has
slot 0x138 (returns the recycle-list owner) and that owner has slot 0x88 (name, out pointer): the mock writes the list
pointer to out. AddWeapon (0x5e9300) and ZLNKWHANDS::PerformDrop (0x4748b0) are hooked and logged (their bodies are other
functions); the name pointer is the image's own string (0x6acf30), so the call log compares it directly."""
from pilot import S
import engine_stubs as E
import pe_emu


def _nostack(x):
    return 'stack' if pe_emu.STACK_TOP - pe_emu.STACK_SIZE <= x < pe_emu.STACK_TOP else x


def _vtable(c, name, nslots, impl, argwords):
    slots = {}
    for i in range(nslots):
        off = 4 * i

        def h(e, r, off=off):
            n = argwords.get(off, 0)
            args = [e.arg32(k) for k in range(n)]
            e.calllog.append((name, off, e.reg('ecx'), tuple(_nostack(x) for x in args)))
            f = impl.get(off)
            eax, st0 = (f(e, args) if f else (0, None))
            e.ret(eax=eax, argbytes=4 * n, st0=st0)
        slots[off] = h
    return c.emu.fake_vtable(name, nslots, slots)


def _hook_callees(c):
    c.emu.hook(0x5e9300, lambda em, r: (em.calllog.append(('addweapon', 0, em.reg('ecx'), (em.arg32(0),))), em.ret(eax=0, argbytes=4)))
    c.emu.hook(0x4748b0, lambda em, r: (em.calllog.append(('lnk_performdrop', 0, em.reg('ecx'), (em.arg32(0),))), em.ret(eax=0, argbytes=4)))


def _gen(c):
    r = c.rng
    eng = E.zero_obj(c, 0x2000)
    E.set_global(c, 0x70039c, eng)
    c.emu.w32(eng + 0x1b5d, 1 if r.random() < 0.6 else r.randrange(0, 4))
    lst = r.getrandbits(32) | 0x10000000
    owner = E.zero_obj(c, 0x40)

    def m88(e, a):
        e.w32(a[1], lst)
        return (None, None)

    ovt = _vtable(c, 'ZRECYCLEOWNER', 0x88 // 4 + 1, {0x88: m88}, {0x88: 2})
    c.emu.w32(owner, ovt)
    en = E.zero_obj(c, 0x40)
    envt = _vtable(c, 'ZENGINE2', 0x138 // 4 + 1, {0x138: lambda e, a: (owner, None)}, {})
    c.emu.w32(en, envt)
    c.emu.w32(eng + 0x9b, en)
    self_ = E.zero_obj(c, 0x40)
    item = r.getrandbits(32)
    c.emu.mu.ctl_flush_tb()
    return [self_, item]


S(0x5a1a60, 'ZFFActor::PerformDrop(ZItem*)', 'thiscall', None, ret=None, gen=_gen, setup=_hook_callees,
  note='unclaimed-43 batch 312 (core residue-02); AddWeapon and ZLNKWHANDS::PerformDrop are hooked')

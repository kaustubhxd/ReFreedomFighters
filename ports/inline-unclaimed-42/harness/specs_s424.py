"""specs_s424.py - unclaimed-42 batch 4 (claim 4): ZFenceGate scalar deleting destructor (0x5c24d0), thiscall, ret 4.
The sub-object destructors (0x4ccf60) run original code on zeroed blocks. The engine object at 0x70039c has a pointer at
+0x9b to a logging object whose slot +0x34 logs. The hook pointer at 0x7003b0 is a stub (non-null, the original traps on
null). The sized delete (0x4690b0) is hooked and logged, not run."""
from pilot import S
from engine_stubs import zero_obj, logged_obj, set_global


def _hook_delete(c):
    c.emu.hook(0x4690b0, lambda em, r: (em.calllog.append(('delete_sized', 0, 0, (em.arg32(0), em.arg32(1)))), em.ret(eax=0, argbytes=0)))


def _gen(c):
    self_ = zero_obj(c, 0x400)
    en = logged_obj(c, 'ZEngineObj', 0x40, impl={}, argwords={0x34: 1})
    eng = zero_obj(c, 0x400)
    c.emu.w32(eng + 0x9b, en)
    set_global(c, 0x70039c, eng)
    hook_addr = c.emu.stub_fn('ZFenceGate hook', lambda em, r: (em.calllog.append(('hook', 0, em.reg('ecx'), ())), em.ret(eax=0, argbytes=0)))
    set_global(c, 0x7003b0, hook_addr)
    flags = c.rng.getrandbits(32)
    if c.rng.random() < 0.7:
        flags |= 1
    return [self_, flags]


S(0x5c24d0, 'ZFenceGate::~ZFenceGate (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen,
  setup=_hook_delete, note='unclaimed-42 batch 4; sub-dtors 0x4ccf60 original; engine slot +0x34; hook 0x7003b0; delete 0x4690b0 hooked')

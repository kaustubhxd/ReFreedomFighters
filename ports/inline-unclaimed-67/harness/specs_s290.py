"""specs_s290.py - unclaimed area 67, gap band: 0x5f1b90 (byte store into the record, or the hook when the record is null).
The hook at 0x7003b0 is a recording stub that returns eax = 0x55."""
from pilot import S

HOOK = 0x5f5012


def _hook_stub(e, r):
    e.calllog.append(('hook290',))
    e.ret(eax=0x55, argbytes=0)


def _case(c):
    c.emu.hook(HOOK, _hook_stub)
    c.emu.w32(0x7003b0, HOOK)
    o = c.emu.alloc(0x40, 4)
    c.emu.wbytes(o, bytes(c.rng.getrandbits(8) for _ in range(0x40)))
    holder = c.emu.alloc(0x10, 4)
    c.emu.w32(holder, o if c.rng.random() < 0.7 else 0)
    self_ = c.emu.alloc(0x20, 4)
    c.emu.wbytes(self_, bytes(c.rng.getrandbits(8) for _ in range(0x20)))
    c.emu.w32(self_ + 0xc, holder)
    c.emu.mu.ctl_flush_tb()
    return [self_, c.rng.getrandbits(32)]


S(0x5f1b90, 'FUN_5f1b90 (storeByteOrHook1b90)', 'thiscall', None, ret='eax', gen=_case, note='batch290; byte store or hook')

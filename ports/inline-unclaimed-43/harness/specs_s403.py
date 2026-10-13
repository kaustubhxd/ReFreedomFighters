"""specs_s403.py - gap band parked rows 0x41f540 (EnterCriticalSection) and 0x41f690 (LeaveCriticalSection), cdecl, no
arguments. The imports are stubbed by name and log their argument (the critical section address 0x6fd228); they return nothing."""
from pilot import S


def _setup(c):
    def enter(em, rr):
        em.calllog.append(('EnterCriticalSection', 0, 0, (em.arg32(0),)))
        em.ret(eax=0, argbytes=4)

    def leave(em, rr):
        em.calllog.append(('LeaveCriticalSection', 0, 0, (em.arg32(0),)))
        em.ret(eax=0, argbytes=4)

    c.emu.stub_import('EnterCriticalSection', enter)
    c.emu.stub_import('LeaveCriticalSection', leave)


def _gen(c):
    c.emu.mu.ctl_flush_tb()
    return []


S(0x41f540, 'EnterCriticalSection forwarder (gap band parked) cdecl', 'cdecl', None, ret=None, gen=_gen, setup=_setup,
  note='gap band parked row; import stubbed by name')
S(0x41f690, 'LeaveCriticalSection forwarder (gap band parked) cdecl', 'cdecl', None, ret=None, gen=_gen, setup=_setup,
  note='gap band parked row; import stubbed by name')

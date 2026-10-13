"""specs_s402.py - gap band parked row 0x420200 (stdcall, one argument vk). The import GetAsyncKeyState (USER32, IAT 0x6761a0)
is stubbed by name: it returns a dword drawn in gen (so both bit states occur); the argument vk is a random byte."""
from pilot import S

SHARED = {'ret': 0}


def _setup(c):
    def h(em, rr):
        em.calllog.append(('GetAsyncKeyState', 0, 0, (em.arg32(0) & 0xffff,)))
        em.ret(eax=SHARED['ret'], argbytes=4)
    c.emu.stub_import('GetAsyncKeyState', h)


def _gen(c):
    r = c.rng
    SHARED['ret'] = r.getrandbits(32)
    c.emu.mu.ctl_flush_tb()
    return [r.getrandbits(8)]


S(0x420200, 'key-down bit from GetAsyncKeyState (gap band parked) stdcall', 'stdcall', None, ret='al', gen=_gen, setup=_setup,
  note='gap band parked row; GetAsyncKeyState stubbed by name')

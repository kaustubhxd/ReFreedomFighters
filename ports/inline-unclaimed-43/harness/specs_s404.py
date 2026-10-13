"""specs_s404.py - gap band parked row 0x410f20 (stdcall, one argument: the SDK version; returns a pointer). The import
Direct3DCreate8 (d3d8.dll, IAT 0x67645c) is stubbed by name: it logs its argument and returns a pointer drawn in gen (a
nonzero dword, the same in both builds)."""
from pilot import S

SHARED = {'ret': 0}


def _setup(c):
    def h(em, rr):
        em.calllog.append(('Direct3DCreate8', 0, 0, (em.arg32(0),)))
        em.ret(eax=SHARED['ret'], argbytes=4)
    c.emu.stub_import('Direct3DCreate8', h)


def _gen(c):
    r = c.rng
    SHARED['ret'] = r.randint(1, 0xffffffff)
    c.emu.mu.ctl_flush_tb()
    return [r.choice([120, 220, r.getrandbits(32)])]


S(0x410f20, 'Direct3DCreate8 thunk (gap band parked) stdcall', 'stdcall', None, ret='eax', gen=_gen, setup=_setup,
  note='gap band parked row; import stubbed by name')

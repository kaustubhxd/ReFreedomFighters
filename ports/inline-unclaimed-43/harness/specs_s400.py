"""specs_s400.py - core batch 400: 0x5c56c0 CTargetObtained::Load (thiscall, one unused stack argument, ret 4; returns true).
Callees are hooked by address and logged (GUESS): 0x6352f0 (stdcall, one pointer argument) stores a dword drawn in gen through its
pointer; 0x5c56f0 (thiscall, one pointer argument) logs ECX and the dword at its pointer and changes nothing. The object is random
bytes, so the bit 6 clear at +4 shows in the heap compare."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S
import engine_stubs as E
import pe_emu

SHARED = {'v': 0}


def _nostack(x):
    return 'stack' if pe_emu.STACK_TOP - pe_emu.STACK_SIZE <= x < pe_emu.STACK_TOP else x


def _setup(c):
    def h6352(em, r):
        p = em.arg32(0)
        em.calllog.append(('get6352f0', 0, 0, (_nostack(p),)))
        em.mu.mem_write(p, SHARED['v'].to_bytes(4, 'little'))
        em.ret(eax=0, argbytes=4)

    def h5c56(em, r):
        p = em.arg32(0)
        em.calllog.append(('load5c56f0', 0, em.reg('ecx') & 0xffffffff, (_nostack(p), int.from_bytes(em.mu.mem_read(p, 4), 'little'))))
        em.ret(eax=0, argbytes=4)

    c.emu.hook(0x6352f0, h6352)
    c.emu.hook(0x5c56f0, h5c56)


def _gen(c):
    r = c.rng
    SHARED['v'] = r.getrandbits(32)
    o = E.zero_obj(c, 0x100)
    c.emu.wbytes(o, bytes(r.getrandbits(8) for _ in range(0x100)))
    c.emu.mu.ctl_flush_tb()
    return [o, r.getrandbits(32)]


S(0x5c56c0, 'CTargetObtained::Load (core) thiscall', 'thiscall', None, ret='al', gen=_gen, setup=_setup,
  note='core batch 400; callees 0x6352f0 and 0x5c56f0 hooked (GUESS)')

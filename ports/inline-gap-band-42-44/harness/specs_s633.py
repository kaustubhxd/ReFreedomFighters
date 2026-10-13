"""specs_s633.py - band 0x421000-0x441000, batch 633 (see src/batch633.cpp).
0x426660: ZSysFileGC::Close(void*). Calls ext_676070(arg); if nonzero, returns it;
else logs via logger object at 0x700390 calling slots 0x20 then 0x2c.
For now: ext_676070 always succeeds (returns 1), so logging path is not exercised.
TODO: make ext_676070 fail 20% of the time to test logging path.
"""
import os
import sys

for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)

from pilot import S  # noqa: E402
import serial_stubs as ss  # noqa: E402


def _rec(name, off, nargs, ret):
    """Recording handler factory."""
    def h(e, rr):
        args = tuple(e.arg32(k) for k in range(nargs))
        e.calllog.append((name, off, e.reg('ecx'), args))
        # For logger.20, return a fake object for the next call
        if name == 'logger.20':
            result = e.emu.fake_object('log_result', 0x40, nslots=0x20, slots={
                0x2c: _rec('logger_result.2c', 0x2c, 2, 0),
            })
            e.ret(eax=result, argbytes=4*nargs)
        else:
            e.ret(eax=ret, argbytes=4*nargs)
    return h


def _gen(c):
    r = c.rng
    # Create logger object with recording vtable
    logger = c.emu.fake_object('logger', 0x40, nslots=0x100, slots={
        0x20: _rec('logger.20', 0x20, 2, 0),
        0x2c: _rec('logger_result.2c', 0x2c, 2, 0),
    })
    c.emu.w32(0x700390, logger)
    # Patch IAT slot 0x676070 with stub that returns 1 (success)
    # The IAT slot contains a function pointer that gets called with stdcall(one arg)
    stub_addr = ss.rec(c, 1, ret=1)
    c.emu.w32(0x676070, stub_addr)
    c.emu._image_dirty = True
    # Test argument: allocate valid memory (file pointer)
    file_ptr = c.emu.alloc(0x100, 16)
    c.emu.wbytes(file_ptr, bytes(c.rng.getrandbits(8) for _ in range(0x100)))
    return [file_ptr]


S(0x426660, 'ZSysFileGC::Close(void*)', 'stdcall', None, ret='al', gen=_gen)

"""specs_s399.py - gap band parked row 0x41e080 (cdecl, no arguments). The file global 0x6fd1a4 points at a dummy block.
Imports are stubbed by name: ftell returns the drawn length N (0..0x5000), rewind does nothing, fread copies the drawn
bytes (count * size, up to the count given) into the buffer, fclose returns 0. The parser 0x42ad40 is hooked by address and
logged (GUESS: body not ported). The exe's stack cookie is not reproduced by the port."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S
import engine_stubs as E
import pe_emu


def _nostack(x):
    return 'stack' if pe_emu.STACK_TOP - pe_emu.STACK_SIZE <= x < pe_emu.STACK_TOP else x

SHARED = {'N': 0, 'data': b''}


def _setup(c):
    def ftell(em, rr):
        em.ret(eax=SHARED['N'], argbytes=0)

    def rewind(em, rr):
        em.calllog.append(('rewind', 0, 0, (em.arg32(0),)))
        em.ret(eax=0, argbytes=0)

    def fread(em, rr):
        buf, size, count = em.arg32(0), em.arg32(1), em.arg32(2)
        n = min(size * count, len(SHARED['data']))
        em.mu.mem_write(buf, SHARED['data'][:n])
        em.calllog.append(('fread', 0, 0, (size, count)))
        em.ret(eax=count if size else 0, argbytes=0)

    def fclose(em, rr):
        em.calllog.append(('fclose', 0, 0, (em.arg32(0),)))
        em.ret(eax=0, argbytes=0)

    c.emu.stub_import('ftell', ftell)
    c.emu.stub_import('rewind', rewind)
    c.emu.stub_import('fread', fread)
    c.emu.stub_import('fclose', fclose)
    c.emu.hook(0x42ad40, lambda em, r: (em.calllog.append(('parse42ad40', 0, 0, (em.arg32(0), em.arg32(1), _nostack(em.arg32(2)), em.mu.mem_read(em.arg32(2) + 0x3fff, 1)[0]))),
                                        em.ret(eax=0, argbytes=12)))


def _gen(c):
    r = c.rng
    SHARED['N'] = r.choice([0, 1, 0x40, r.randint(0, 0x3ffe), r.randint(0x3fff, 0x5000)])
    SHARED['data'] = bytes(r.getrandbits(8) for _ in range(0x5000))
    f = E.zero_obj(c, 0x20)
    E.set_global(c, 0x6fd1a4, f)
    c.emu.mu.ctl_flush_tb()
    return []


S(0x41e080, 'read file into parser (gap band parked) cdecl', 'cdecl', None, ret=None, gen=_gen, setup=_setup,
  note='gap band parked row, now ported with 0x42ad40 hooked (GUESS); imports stubbed by name')

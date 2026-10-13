"""specs_s797.py - unclaimed-77 claims 35 to 38 (docs/20-unclaimed-77.md), residue 4. Stubs (GUESS): 0x43de70 and 0x651380 (tail-jump
targets, replaced by loggers of ecx that store nothing and return plain); slot 0x240 (a counting stub, no arguments); slot 0xc (logs its
argument and returns a pointer to a random 0x100-byte buffer). g_pSysInterface (0x70039c) is a random 0x2000-byte object whose byte at
+0x1a97 is zero in half the cases, so both branches run."""
from pilot import S
import serial_stubs as ss


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _log_ecx(c):
    """Thiscall, no arguments, plain ret: logs ecx in an 8-entry ring, writes nothing."""
    cnt = c.emu.alloc(4, 4)
    c.emu.w32(cnt, 0)
    ring = c.emu.alloc(32, 4)
    c.emu.wbytes(ring, bytes(32))
    b = (b'\xa1' + ss.P(cnt) + b'\x83\xe0\x07\xc1\xe0\x02\x05' + ss.P(ring)
         + b'\x89\x08' + b'\xff\x05' + ss.P(cnt) + b'\xc3')
    return ss.code(c, b)


def _gen_44e700(c):
    ss.patch(c, 0x43de70, _log_ecx(c))
    return [_rnd(c, 0x1000)]


def _gen_658c80(c):
    ss.patch(c, 0x651380, _log_ecx(c))
    return [_rnd(c, 0x1200)]


def _gen_654a40(c):
    si = _rnd(c, 0x2000)
    if c.rng.random() < 0.5:
        c.emu.wbytes(si + 0x1a97, b'\x00')
    c.emu.w32(0x70039c, si)
    return [ss.mkobj(c, {0x240: ss.rec(c, 0)}, size=0x100)]


def _gen_656fc0(c):
    buf = _rnd(c, 0x100)
    return [ss.mkobj(c, {0xc: ss.rec(c, 1, ret=buf)}, size=0x100), c.rng.getrandbits(32)]


S(0x44e700, 'GUESS FUN_44e700 (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen_44e700,
  note='unclaimed-77 claim 35; stores vtable 0x680abc; 0x43de70 stubbed (GUESS)')
S(0x658c80, 'GUESS FUN_658c80 (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen_658c80,
  note='unclaimed-77 claim 36; zeroes +0x114b/+0x114f; 0x651380 stubbed (GUESS)')
S(0x654a40, 'GUESS FUN_654a40 (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen_654a40,
  note='unclaimed-77 claim 37; slot 0x240 stubbed (GUESS); g_pSysInterface flag')
S(0x656fc0, 'ZPrimControlGC::GetNrBones (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen_656fc0,
  note='unclaimed-77 claim 38; slot 0xc stubbed (GUESS)')

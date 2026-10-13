"""specs_s4144.py - unclaimed-41 batch 44 (core-todo residue-19): 0x4c5530 ZPathfinderControl::CopyData(ZEventBase*) (thiscall, one stack
argument src, ret 4). SEH frame not reproduced (fs:[0] writes not compared).

this: 0x100 random bytes; its +0x48 is an old object R0 (vt[0] checksum) or zero. src: 0x100 random bytes, +0x48 = R1 (or zero one time in
five). R1's vtable: 0x4c and 0x5c are writers: each writes the next value of a sequence through its first argument (the l18 local) and
returns a value. The sequence for 0x5c ends in zero, so the loop ends (at most eight calls per case). The allocator 0x41e290 (cdecl) is a
stub returning a fresh 0x1c-byte buffer A. 0x4ccbe0 (two arguments, callee pops) is a checksum stub returning NR, an object whose vt[4] is a
one-argument checksum stub. Faulting cases must be 0 (JSON)."""
import struct
from pilot import S
import helper_stubs as hs
import serial_stubs as ss

P = lambda v: struct.pack('<I', v & 0xffffffff)


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _vt(c, slots):
    vt = c.emu.alloc(0x400, 4)
    for off, st in slots.items():
        c.emu.w32(vt + off, st)
    return vt


def _wseq(c, vals, rets):
    """Writes vals[k] through its first argument (a pointer) and returns rets[k] in eax, k = call count mod 8. Callee pops 4."""
    vals = list(vals)[:8]
    vals = vals + [vals[-1]] * (8 - len(vals))
    rets = list(rets)[:8]
    rets = rets + [rets[-1]] * (8 - len(rets))
    vtab = c.emu.alloc(32, 4)
    c.emu.wbytes(vtab, b''.join(P(v) for v in vals))
    rtab = c.emu.alloc(32, 4)
    c.emu.wbytes(rtab, b''.join(P(v) for v in rets))
    cnt = c.emu.alloc(4, 4)
    c.emu.w32(cnt, 0)
    b = (b'\x8b\x0d' + P(cnt)            # mov ecx, [cnt]
         + b'\x83\xe1\x07'               # and ecx, 7
         + b'\xff\x05' + P(cnt)          # inc dword [cnt]
         + b'\x8b\x14\x8d' + P(vtab)     # mov edx, [vtab + ecx*4]
         + b'\x8b\x44\x24\x04'           # mov eax, [esp+4]
         + b'\x89\x10'                   # mov [eax], edx
         + b'\x8b\x04\x8d' + P(rtab)     # mov eax, [rtab + ecx*4]
         + b'\xc2\x04\x00')              # ret 4
    return ss.code(c, b)


def _layout(c):
    # the allocator (cdecl): returns a fresh buffer A
    A = _rnd(c, 0x40)
    ss.patch(c, 0x41e290, ss.code(c, b'\xb8' + P(A) + b'\xc3'))

    # NR: the object returned by 0x4ccbe0, with vt[4] a one-argument checksum stub
    s4, _, _ = hs.stub(c, 1, ecx=True, edx=False, mask=[1], cleanup=True, ret=0)
    NR = _rnd(c, 0x40)
    c.emu.w32(NR, _vt(c, {4: s4}))
    s4cc, _, _ = hs.stub(c, 2, ecx=True, edx=False, mask=[1, 2], cleanup=True, ret=NR)
    ss.patch(c, 0x4ccbe0, s4cc)

    # R1 (src+0x48): writers for 0x4c and 0x5c; the 0x5c sequence ends in zero
    n = c.rng.randint(0, 4)
    vals5c = [c.rng.choice([1, 2, 0x12345]) for _ in range(n)] + [0]
    rets5c = [c.rng.getrandbits(32) for _ in range(len(vals5c))]
    vals4c = [c.rng.choice([0, 1, 7]) for _ in range(3)]
    R1 = _rnd(c, 0x40)
    c.emu.w32(R1, _vt(c, {0x4c: _wseq(c, vals4c, [0]), 0x5c: _wseq(c, vals5c, rets5c)}))

    # R0 (this+0x48): vt[0] checksum stub
    s0, _, _ = hs.stub(c, 1, ecx=True, edx=False, mask=[1], cleanup=True, ret=0)
    R0 = _rnd(c, 0x40)
    c.emu.w32(R0, _vt(c, {0: s0}))

    self_ = _rnd(c, 0x100)
    c.emu.w32(self_ + 0x48, R0 if c.rng.random() < 0.7 else 0)
    src = _rnd(c, 0x100)
    c.emu.w32(src + 0x48, R1 if c.rng.random() < 0.8 else 0)
    return [self_, src]


S(0x4c5530, 'ZPathfinderControl::CopyData(ZEventBase*)', 'thiscall', None, ret=None, gen=_layout,
  note='unclaimed-41 batch 44; SEH frame not reproduced (fs:[0] writes not compared); the allocator 0x41e290 and 0x4ccbe0 are stubs (GUESS); the object slots are stubs or writers (GUESS)')

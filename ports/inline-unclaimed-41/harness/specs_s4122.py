"""specs_s4122.py - unclaimed-41 batch 22 (slice 13): 0x4ac9d0 (GUESS FUN_4ac9d0; thiscall, one stack argument X, ret 4; returns eax).

T: 0x400 random bytes with a vtable (M) at T+0x11a. X: 0x100 random bytes with a vtable (slots 0x100 and 0x10c). The rm global
(0x70039c) points at rm, rm+0x9b is object o (vtable: slot 0x58, slot 0x4c, and vt[0] -> vt2 with slot 0x1e0). Q has slot 0x2f0;
R2 has slot 0x5c. M's slots: 0x14 (a sequence: 1 first, ends in 0), 0x44 and 0x4c and 0x5c (writers: each writes a value through its
first argument, the L14 local, and returns a value; 0x5c returns an object or 0). The unported callees are checksum or writer
stubs (GUESS): 0x4ad770, and the slots of the objects above. Stack-local pointers (&L14) are not in any checksum; the values
written through them are compared through the branches they take. Faulting cases must be 0 (JSON)."""
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


def _o58(c, Q, D0):
    """o.vt[+0x58] stand-in: returns 0 when its argument is D0 (the null-object branch) and Q otherwise. D0 is only handed out by
    the 0x5c writer where the loop continues, so the block call (which dereferences its result) never receives D0. Checksums its
    first argument (edi) and counts calls."""
    cnt = c.emu.alloc(4, 4)
    acc = c.emu.alloc(4, 4)
    c.emu.w32(cnt, 0)
    c.emu.w32(acc, 0)
    b = (b'\x8b\x44\x24\x04'                 # mov eax, [esp+4]
         + b'\x01\x05' + P(acc)               # add [acc], eax
         + b'\x3d' + P(D0)                     # cmp eax, D0
         + b'\x75\x05'                        # jne +5 (over mov eax, 0)
         + b'\xb8' + P(0)                      # mov eax, 0
         + b'\xeb\x05'                        # jmp +5 (over mov eax, Q)
         + b'\xb8' + P(Q)                      # mov eax, Q
         + b'\xff\x05' + P(cnt)               # inc dword [cnt]
         + b'\xc2\x04\x00')                  # ret 4
    return ss.code(c, b)


def _layout(c):
    Q = _rnd(c, 0x40)
    Q_vt = _vt(c, {0x2f0: hs.stub(c, 1, ecx=True, edx=False, cleanup=True, ret=0)[0],
                   0x1e0: hs.stub(c, 1, ecx=True, edx=False, mask=[1], cleanup=True, ret=c.rng.randint(0, 1))[0]})
    c.emu.w32(Q, Q_vt)

    R2 = _rnd(c, 0x40)
    R2_vt = _vt(c, {0x5c: hs.stub(c, 3, ecx=True, edx=False, mask=[1, 2, 3], cleanup=True, ret=0)[0]})
    c.emu.w32(R2, R2_vt)

    # the 0x100 result r is zero about half the time; the 0x10c result is R2 (nonzero) or 0
    r = 0 if c.rng.random() < 0.5 else (c.rng.getrandbits(31) | 1)
    r2 = R2 if c.rng.random() < 0.8 else 0
    X = _rnd(c, 0x100)
    X_vt = _vt(c, {0x100: hs.stub(c, 1, ecx=True, edx=False, mask=[1], cleanup=True, ret=r)[0],
                   0x10c: hs.stub(c, 2, ecx=True, edx=False, mask=[1, 2], cleanup=True, ret=r2)[0]})
    c.emu.w32(X, X_vt)

    # M (T+0x11a): the 0x14 sequence starts with 1 (enter) and ends with 0; the writers set L14
    seq14 = [1] + [c.rng.choice([0, 1]) for _ in range(c.rng.randint(0, 5))] + [0]
    s14 = ss.seqr(c, 0, seq14)
    vals44 = [c.rng.choice([0, 1, 2, 0x12345]) for _ in range(7)] + [0]
    vals4c = [c.rng.choice([0, 1, 2, 0x12345]) for _ in range(7)] + [0]
    vals5c = [c.rng.choice([0, 1, 2, 0x12345]) for _ in range(7)] + [0]
    D0 = _rnd(c, 0x40)
    # 0x5c result: D0 only where L14 is non-zero (the loop continues); never where L14 is zero
    rets5c = [c.rng.choice([D0, Q, 0]) if v != 0 else c.rng.choice([Q, 0]) for v in vals5c]
    M_vt = _vt(c, {0x14: s14,
                   0x44: _wseq(c, vals44, [0]),
                   0x4c: _wseq(c, vals4c, [0]),
                   0x5c: _wseq(c, vals5c, rets5c)})
    T = _rnd(c, 0x400)
    c.emu.w32(T + 0x11a, M_vt)

    # o (rm+0x9b): slot 0x58 returns Q or 0 (an object), slot 0x4c takes (X, 0, 1) and returns a value
    o_vt = _vt(c, {0x58: _o58(c, Q, D0),
                   0x4c: hs.stub(c, 3, ecx=True, edx=False, mask=[1, 2, 3], cleanup=True, ret=c.rng.getrandbits(32))[0]})
    vt2 = _vt(c, {0x1e0: hs.stub(c, 1, ecx=True, edx=False, mask=[1], cleanup=True, ret=c.rng.randint(0, 1))[0]})
    c.emu.w32(o_vt, vt2)            # the vtable's own first dword is a vtable whose slot 0x1e0 gives the bool
    o = _rnd(c, 0x40)
    c.emu.w32(o, o_vt)
    rm = _rnd(c, 0x200)
    c.emu.w32(rm + 0x9b, o)
    c.emu.w32(0x70039c, rm)

    s, _, _ = hs.stub(c, 1, ecx=True, edx=False, mask=[1], cleanup=True, ret=0)
    ss.patch(c, 0x4ad770, s)
    c.emu._image_dirty = True
    return [T, X]


S(0x4ac9d0, 'GUESS FUN_4ac9d0 (ZPlayer-area dispatch; name from the residue-13 list)', 'thiscall', None, ret='eax', gen=_layout,
  note='unclaimed-41 batch 22; 0x4ad770 and the object slots are checksum or writer stubs (GUESS); the /GS cookie check is not reproduced')

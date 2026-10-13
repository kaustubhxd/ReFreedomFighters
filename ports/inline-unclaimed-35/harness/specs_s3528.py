"""specs_s3528.py - area 35 claim 28 (docs/20-unclaimed-35.md): 0x55ef10 ZFFHeroIf::BeamToSpawnPoint(...) (residue name).

Fake object graph (the exe's globals are at their real addresses):
  this -> +0x18 O; O -> +0xeee P (entry 0), +0x54 R; P -> +0x18 X; X vtable: +0x14 (count), +0x30 (r1).
  mgr (0x70039c) -> +0x9b M; M vtable: +0x58 (returns the next object of a pool: pool[0] is T1, the rest are Q objects with
  vtable +0x80, +0x1e0 and +8 -> A8 floats), +0x114 (four args, returns a 16-bit value); mgr vtable +0x1c0 (float return).
  G8 (0x7003b8) -> +0x2c11 B (vtable +0x88 returns a per-case sequence, +0x90), +0x2c21 Z.
  G (0x700390): vtable +0x20 returns W (cdecl slot +0x30 logs its arguments).
GUESS recording stubs for rand, memcpy (IAT slots 0x67644c, 0x67626c, forward copy), 0x5a4720, 0x4e0830 (float), 0x451890,
0x55f900; 0x633654 is a no-op."""
import os
import struct
import sys

for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss   # noqa: E402

from pilot import S   # noqa: E402


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _fl(c, lo, hi):
    return struct.unpack('<f', struct.pack('<f', c.rng.uniform(lo, hi)))[0]


def _fbits(v):
    return struct.unpack('<I', struct.pack('<f', v))[0]


def _stub(c, regs, stack, cleanup, ret_eax=0, ret_float=None):
    """GUESS recording stub (as in specs_s3526): call count, the three dwords behind 'p' pointers, GUESS output written there."""
    nslots = 1 + sum(3 if k == 'p' else 1 for _, k in regs) + sum(3 if k == 'p' else 1 for k in stack)
    cells = c.emu.alloc(4 * nslots, 4)
    c.emu.wbytes(cells, bytes(4 * nslots))
    cnt = c.emu.alloc(4, 4)
    c.emu.w32(cnt, 0)
    code = b'\xff\x05' + ss.P(cnt) + b'\xa1' + ss.P(cnt) + b'\xa3' + ss.P(cells)
    pos = 1

    def dw():
        return struct.pack('<I', c.rng.getrandbits(32) if c.rng.random() < 0.85 else 0)
    for reg, kind in regs:
        base = b'\x8b\x01' if reg == 'ecx' else b'\x8b\x02'
        if kind == 'p':
            for j in (0, 4, 8):
                ld = base if j == 0 else (b'\x8b\x41' + bytes([j]) if reg == 'ecx' else b'\x8b\x42' + bytes([j]))
                code += ld + b'\xa3' + ss.P(cells + 4 * pos)
                pos += 1
            for j in (0, 4, 8):
                code += (b'\xc7\x41' if reg == 'ecx' else b'\xc7\x42') + bytes([j]) + dw()
        else:
            code += (b'\x89\xc8' if reg == 'ecx' else b'\x89\xd0') + b'\xa3' + ss.P(cells + 4 * pos)
            pos += 1
    for k, kind in enumerate(stack):
        d = 4 + 4 * k
        if kind == 'p':
            code += b'\x8b\x54\x24' + bytes([d])
            for j in (0, 4, 8):
                code += b'\x8b\x42' + bytes([j]) + b'\xa3' + ss.P(cells + 4 * pos)
                pos += 1
            for j in (0, 4, 8):
                code += b'\xc7\x42' + bytes([j]) + dw()
        else:
            code += b'\x8b\x44\x24' + bytes([d]) + b'\xa3' + ss.P(cells + 4 * pos)
            pos += 1
    if ret_float is not None:
        rf = c.emu.alloc(4, 4)
        c.emu.wbytes(rf, struct.pack('<f', ret_float))
        code += b'\xd9\x05' + ss.P(rf)
    else:
        code += b'\xb8' + ss.P(ret_eax)
    code += (b'\xc2' + struct.pack('<H', cleanup)) if cleanup else b'\xc3'
    return ss.code(c, code)


def _seqret(c, tab, cleanup):
    """thiscall: returns tab[cnt] (eax), cnt += 1; the stack args are only cleaned, not logged."""
    cnt = c.emu.alloc(4, 4)
    c.emu.w32(cnt, 0)
    tb = c.emu.alloc(4 * len(tab), 4)
    c.emu.wbytes(tb, b''.join(ss.P(v) for v in tab))
    code = b'\xa1' + ss.P(cnt) + b'\x8b\x04\x85' + ss.P(tb) + b'\xff\x05' + ss.P(cnt)
    code += (b'\xc2' + struct.pack('<H', cleanup)) if cleanup else b'\xc3'
    return ss.code(c, code)


def _seq2(c, tabL, tabR):
    """thiscall, one pointer arg: writes tabL[cnt] through it, returns tabR[cnt]; cnt += 1."""
    cnt = c.emu.alloc(4, 4)
    c.emu.w32(cnt, 0)
    tl = c.emu.alloc(4 * len(tabL), 4)
    c.emu.wbytes(tl, b''.join(ss.P(v) for v in tabL))
    tr = c.emu.alloc(4 * len(tabR), 4)
    c.emu.wbytes(tr, b''.join(ss.P(v) for v in tabR))
    code = (b'\x8b\x54\x24\x04'                         # mov edx, [esp+4]
            + b'\xa1' + ss.P(cnt)                        # mov eax, [cnt]
            + b'\x8b\x0c\x85' + ss.P(tl)                 # mov ecx, [tl + eax*4]
            + b'\x89\x0a'                                # mov [edx], ecx
            + b'\x8b\x0c\x85' + ss.P(tr)                 # mov ecx, [tr + eax*4]
            + b'\xff\x05' + ss.P(cnt)                    # inc dword [cnt]
            + b'\x89\xc8'                                # mov eax, ecx
            + b'\xc2\x04\x00')                           # ret 4
    return ss.code(c, code)


def _rand_seq(c, tab):
    """cdecl, no args: returns tab[cnt] in eax, cnt += 1 (the exe's rand)."""
    cnt = c.emu.alloc(4, 4)
    c.emu.w32(cnt, 0)
    tb = c.emu.alloc(4 * len(tab), 4)
    c.emu.wbytes(tb, b''.join(ss.P(v) for v in tab))
    code = b'\xa1' + ss.P(cnt) + b'\x8b\x04\x85' + ss.P(tb) + b'\xff\x05' + ss.P(cnt) + b'\xc3'
    return ss.code(c, code)


def _memcpy_fwd(c):
    """cdecl memcpy(dst, src, n): forward byte copy (rep movsb). GUESS for the overlap behaviour of VCRUNTIME140 memcpy."""
    code = (b'\x56\x57'                                  # push esi; push edi
            + b'\x8b\x7c\x24\x0c'                        # mov edi, [esp+12]  (dst)
            + b'\x8b\x74\x24\x10'                        # mov esi, [esp+16]  (src)
            + b'\x8b\x4c\x24\x14'                        # mov ecx, [esp+20]  (n)
            + b'\xfc\xf3\xa4'                            # cld; rep movsb
            + b'\x5f\x5e\xc3')                           # pop edi; pop esi; ret
    return ss.code(c, code)


def _cdecl_log(c, nargs):
    cells = c.emu.alloc(4 * nargs, 4)
    c.emu.wbytes(cells, bytes(4 * nargs))
    code = b''
    for i in range(nargs):
        code += b'\x8b\x44\x24' + bytes([4 + 4 * i]) + b'\xa3' + ss.P(cells + 4 * i)
    code += b'\xb8' + ss.P(0) + b'\xc3'
    return ss.code(c, code)


def _ret_n(c, n):
    return ss.code(c, b'\xc2' + struct.pack('<H', n) if n else b'\xc3')


def _float_indexed(c):
    """fastcall (ecx, edx, float stack arg): logs the float of every call, indexed by the call count (ecx and edx are not
    logged: edx is a stack address and ecx points into the caller's frame)."""
    cnt = c.emu.alloc(4, 4)
    c.emu.w32(cnt, 0)
    flog = c.emu.alloc(4 * 8, 4)
    c.emu.wbytes(flog, bytes(32))
    code = (b'\x8b\x0d' + ss.P(cnt)                            # mov ecx, [cnt]
            + b'\x8b\x44\x24\x04'                            # mov eax, [esp+4]  (the float)
            + b'\x89\x04\x8d' + ss.P(flog)                    # mov [flog + ecx*4], eax
            + b'\xff\x05' + ss.P(cnt)                          # inc dword [cnt]
            + b'\xc2\x04\x00')
    return ss.code(c, code)


def _disp(c):
    self_obj = _rnd(c, 0x200)
    O = _rnd(c, 0x1000)
    P = _rnd(c, 0x200)
    X = _rnd(c, 0x200)
    R = _rnd(c, 0x40)
    QO = _rnd(c, 0x40)
    c.emu.w32(self_obj + 0x18, O)
    c.emu.w32(O + 0xeee, P if c.rng.random() < 0.85 else 0)   # P == 0 takes the Lp0 exit
    c.emu.w32(O + 0x54, R)
    c.emu.w32(P + 0x18, X)
    c.emu.w32(R + 4, c.rng.getrandbits(32))
    c.emu.w32(R + 0xc, _fbits(_fl(c, -3.0, 3.0)))
    c.emu.w32(R + 0x10, _fbits(_fl(c, -3.0, 3.0)))
    c.emu.w32(QO + 4, c.rng.getrandbits(32))
    c.emu.wbytes(QO + 4, struct.pack('<I', c.rng.getrandbits(32)))
    c14 = c.rng.randint(1, 12)
    r1 = c.rng.randint(0, 20)
    c.emu.w32(X, c.emu.alloc(4, 4))   # placeholder: X has no field of its own (vtable set below)
    xvt = c.emu.fake_vtable('ZBeamX', 0x40, {0x14: _stub(c, [], [], 0, ret_eax=c14),
                                             0x30: _stub(c, [], ['v'], 4, ret_eax=r1)})
    c.emu.w32(X, xvt)
    ovt = c.emu.fake_vtable('ZBeamO', 0x380, {
        0x84: _stub(c, [], ['p'], 4),
        0x370: _stub(c, [], ['p', 'p'], 8),
        0x20: _stub(c, [], [], 0, ret_eax=QO),
    })
    c.emu.w32(O, ovt)
    # the pool for M.vt58: T1 first (its vtable has +0x128), then Q objects (vtable +0x80, +0x1e0; +8 -> A8; +0x18 -> X)
    al_q = c.rng.choice([0, 1])
    qvt = c.emu.fake_vtable('ZBeamQ', 0x1e8, {
        0x80: _stub(c, [], ['p', 'p'], 8),
        0x1e0: _stub(c, [], ['v'], 4, ret_eax=al_q),
        0x128: _stub(c, [], ['v', 'p', 'v'], 12),
    })
    pool = []
    for _ in range(41):
        q = _rnd(c, 0x80)
        a8 = _rnd(c, 0x80)
        c.emu.w32(q, qvt)
        c.emu.w32(q + 8, a8)
        c.emu.w32(q + 0x18, X)
        c.emu.wbytes(a8 + 0x40, struct.pack('<f', _fl(c, -3.0, 3.0)))
        c.emu.wbytes(a8 + 0x48, struct.pack('<f', _fl(c, -3.0, 3.0)))
        pool.append(q)
    M = _rnd(c, 0x100)
    r16 = c.rng.getrandbits(16)
    mvt = c.emu.fake_vtable('ZBeamM', 0x120, {
        0x58: _seqret(c, pool, 4),
        0x114: _stub(c, [], ['v', 'v', 'v', 'v'], 16, ret_eax=r16),
    })
    c.emu.w32(M, mvt)
    mgr = _rnd(c, 0x2000)
    c.emu.w32(mgr + 0x9b, M)
    c.emu.w32(0x70039c, mgr)
    t = _fl(c, -2.0, 2.0)
    gvt = c.emu.fake_vtable('ZBeamMgr', 0x1c8, {0x1c0: _stub(c, [], ['v', 'v'], 8, ret_float=t)})
    c.emu.w32(mgr, gvt)
    # G8 and B, Z
    G8 = _rnd(c, 0x2c40)
    B = _rnd(c, 0x200)
    Z = _rnd(c, 0x40)
    c.emu.w32(G8 + 0x2c11, B)
    c.emu.w32(G8 + 0x2c21, Z)
    c.emu.w32(0x7003b8, G8)
    pat = c.rng.random()
    if pat < 0.3:
        seq88 = [0] + [0] * 7                 # straight to the float block
    elif pat < 0.6:
        seq88 = [0, O, O, 0] + [0] * 4        # the L331 loop runs twice
    elif pat < 0.85:
        seq88 = [O, 0] + [0] * 6              # first test fails
    else:
        seq88 = [7, 0] + [0] * 6              # neither zero nor O
    bvt = c.emu.fake_vtable('ZBeamB', 0x94, {0x88: _seqret(c, seq88, 24), 0x90: _stub(c, [], ['v'], 4)})
    c.emu.w32(B, bvt)
    # the 5a4720 result X0 and its vtable (+0x4c no-op, +0x5c writes a sequence and returns one)
    x0 = _rnd(c, 0x100)
    kk = c.rng.randint(0, 2)
    tabL = ([1] * kk + [0] * 8)[:8]
    tabR = [c.rng.randint(0, 16) for _ in range(8)]
    x0vt = c.emu.fake_vtable('ZBeamX0', 0x64, {0x4c: _ret_n(c, 4), 0x5c: _seq2(c, tabL, tabR)})
    c.emu.w32(x0, x0vt)
    ss.patch(c, 0x5a4720, _stub(c, [('ecx', 'v')], ['v'], 4, ret_eax=x0 if c.rng.random() < 0.85 else 0))
    # G (0x700390) and the cdecl W
    G = _rnd(c, 0x100)
    W = _rnd(c, 0x100)
    wvt = c.emu.fake_vtable('ZBeamW', 0x40, {0x30: _cdecl_log(c, 3)})
    c.emu.w32(W, wvt)
    gvt2 = c.emu.fake_vtable('ZBeamG', 0x40, {0x20: _stub(c, [('ecx', 'v')], ['v', 'v'], 8, ret_eax=W)})
    c.emu.w32(G, gvt2)
    c.emu.w32(0x700390, G)
    # helpers
    rnd = [c.rng.randrange(0, 0x8000) for _ in range(64)]
    key = struct.unpack('<f', struct.pack('<I', 0x7e967699))[0]
    f_ret = key if c.rng.random() < 0.5 else _fl(c, -2.0, 4.0)     # key ties with f in half the cases
    ss.patch(c, 0x4e0830, _stub(c, [('ecx', 'p'), ('edx', 'p')], [], 0, ret_float=f_ret))
    ss.patch(c, 0x451890, _float_indexed(c))   # logs each call's float (indexed); the single cell hid the first call
    ss.patch(c, 0x55f900, _stub(c, [('ecx', 'v')], ['v', 'p', 'p'], 12))
    ss.patch(c, 0x633654, ss.code(c, b'\xc3'))
    c.emu.w32(0x67644c, _rand_seq(c, rnd))       # rand: IAT slot
    c.emu.w32(0x67626c, _memcpy_fwd(c))          # memcpy: IAT slot
    return [self_obj, c.rng.getrandbits(32)]


S(0x55ef10, 'ZFFHeroIf::BeamToSpawnPoint(OpaqueCallParameters_t&) (residue name) thiscall', 'thiscall', None, ret=None,
  gen=_disp, note='area 35 claim 28; rand and memcpy IAT slots stubbed; object graph fake; SEH not used')

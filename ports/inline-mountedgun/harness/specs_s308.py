"""specs_s308.py - mounted gun batch 308: CFFTools_if::GetMachineGun (nest search). A fake MachinegunList with an
iterator (slot 0x4c begin, slot 0x5c next), nests answering GetCenter/GetTaken/CanAimWeaponRef through cmd_stub."""
import struct
from pilot import S
from mg_helpers import _rnd, _stub, _obj, flush, dispatch, new_log, log_stub, cmd_stub, make_block

NAMES = [0x6a585c, 0x6a5868, 0x6a5874, 0x6a5884]   # GetCenter, GetTaken, CanAimWeaponRef, MakeReservation


def _put(c, vals):
    a = c.emu.alloc(4 * (len(vals) + 8), 4)
    for i in range(len(vals) + 8):
        c.emu.wf32(a + 4 * i, vals[i] if i < len(vals) else c.fv())
    return a


def _iter(c, refs):
    """Iterator object: slot 0x4c(st) resets the cursor and writes st[0] = 0x5eed; slot 0x5c(st) returns refs[k] and
    sets st[0] = 1 (k < n) or 0 (end), then k += 1 (capped)."""
    n = len(refs)
    arr = c.emu.alloc(4 * (n + 2), 4)
    flg = c.emu.alloc(4 * (n + 2), 4)
    for i, v in enumerate(refs):
        c.emu.w32(arr + 4 * i, v)
        c.emu.w32(flg + 4 * i, 1)
    cnt = c.emu.alloc(4, 4)
    begin = (b'\xc7\x05' + struct.pack('<II', cnt, 0) + b'\x8b\x44\x24\x04\xc7\x00' + struct.pack('<I', 0x5eed)
             + b'\xc2\x04\x00')
    nxt = (b'\xa1' + struct.pack('<I', cnt)                       # mov eax, [cnt]
           + b'\x8b\x14\x85' + struct.pack('<I', flg)             # mov edx, [flg + eax*4]
           + b'\x8b\x4c\x24\x04\x89\x11'                          # mov ecx, [esp+4]; mov [ecx], edx
           + b'\x8b\x04\x85' + struct.pack('<I', arr)             # mov eax, [arr + eax*4]
           + b'\x83\x3d' + struct.pack('<I', cnt) + bytes([n])    # cmp dword [cnt], n
           + b'\x73\x06'                                          # jae +6
           + b'\xff\x05' + struct.pack('<I', cnt)                 # inc dword [cnt]
           + b'\xc2\x04\x00')
    a1 = c.emu.alloc(len(begin) + 16, 16)
    c.emu.wbytes(a1, begin)
    a2 = c.emu.alloc(len(nxt) + 16, 16)
    c.emu.wbytes(a2, nxt)
    vt = c.emu.alloc(0x60, 4)
    c.emu.w32(vt + 0x4c, a1)
    c.emu.w32(vt + 0x5c, a2)
    o = _rnd(c, 0x20)
    c.emu.w32(o, vt)
    return o


def _gm(c):
    r = c.rng
    log = new_log(c)
    ids = r.sample(range(1, 0x10000), 4)
    idmap = {k: ids[i] | (r.getrandbits(16) << 16) for i, k in enumerate(NAMES)}
    me, target = r.getrandbits(30) | 1, (r.getrandbits(30) | 1) if r.random() < 0.6 else 0
    mypt = [c.fv(-300, 300) for _ in range(3)]
    meo = _obj(c, 0x40, {0x84: _stub(c, 1, fills=((0, _put(c, mypt), 3),), skip=(0,))})
    refs = {me: meo}
    o2r = {}
    nrefs = []
    for k in range(r.randint(0, 6)):
        ref = r.getrandbits(30) | 1
        cref = r.getrandbits(30) | 1
        center = _obj(c, 0x40, {0x80: _stub(c, 2, fills=((0, _put(c, [c.fv(-1, 1) for _ in range(9)]), 9),
                                                          (1, _put(c, [c.fv(-500, 500) for _ in range(3)]), 3)),
                                             skip=(0, 1))})
        if k and r.random() < 0.25:
            pt = list(last)          # equal distances: exercises the strict best > d test
        elif r.random() < 0.7:
            pt = [max(-3.4e38, min(3.4e38, m + c.fv(-40, 40))) for m in mypt]
        else:
            pt = [c.fv(-300, 300) for _ in range(3)]
        last = pt
        g = _obj(c, 0x40, {0x84: _stub(c, 1, fills=((0, _put(c, pt), 3),), skip=(0,)),
                           0x128: cmd_stub(c, {ids[0]: cref, ids[1]: r.choice([0, 0, 1]),
                                               ids[2]: r.choice([0, target, target])},
                                           log_stub(c, log, 0x128 + k, 3))})
        refs[ref] = g if r.random() < 0.93 else 0
        refs[cref] = center
        o2r[g] = ref
        nrefs.append(ref)
    it = _iter(c, nrefs)
    lst = _rnd(c, 0x40)
    c.emu.w32(lst + 0x18, it if r.random() < 0.95 else 0)
    gd = _rnd(c, 0x2c40)
    c.emu.w32(gd + 0x2c29, lst if r.random() < 0.95 else 0)
    c.emu.w32(0x7003b8, gd)
    eng = _rnd(c, 0x200)
    db = _obj(c, 0x200, {0x114: log_stub(c, log, 0x114, 4, args=(0, 3), chain=dispatch(c, idmap, argbytes=16)), 0x58: dispatch(c, refs),
                         0x4c: dispatch(c, o2r)})
    c.emu.w32(eng + 0x9b, db)
    c.emu.w32(0x70039c, eng)
    pr = _obj(c, 8, {0x2c: _stub(c, 3, pop=0, this=True)})
    lg = _obj(c, 8, {0x20: _stub(c, 2, ret=pr, this=True)})
    c.emu.w32(0x700390, lg)
    c.emu.w32(0x7003b0, log_stub(c, log, 0xa55e, 0))
    rad = c.fv(0, 80) if r.random() < 0.9 else c.fv()
    inb, _ = make_block(c, [(me, 1), (target, 1), (struct.unpack('<I', struct.pack('<f', rad))[0], 2)],
                        first=r.randint(0, 2))
    t = lambda: r.choice([0, 2, 2, 2]) if r.random() < 0.95 else 1
    outb, _ = make_block(c, [(r.getrandbits(32), r.choice([0, 1]))] + [(r.getrandbits(32), t()) for _ in range(3)],
                         first=r.randint(0, 2))
    par = _rnd(c, 0x10)
    c.emu.w32(par + 4, inb)
    c.emu.w32(par + 8, outb)
    flush(c)
    return [_rnd(c, 0x10), par]


S(0x554020, 'CFFTools_if::GetMachineGun', 'thiscall', None, gen=_gm, note='batch308')

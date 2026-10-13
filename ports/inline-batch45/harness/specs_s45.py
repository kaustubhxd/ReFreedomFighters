"""specs_s45.py - inline session batch 45: 0x5e5c00 ZFFHeroMovementBaseMove::Move (walk root).
Callee stand-ins (both runs call the same ones):
  this vtable = copy of the real ZFFHeroMovementBaseMove vtable with slots 0x40 (CalcNewPosAndSpeed) and 0x48
  (CheckCollision) pointed at heap recorder stubs that save their five stack args and count calls;
  player vtable slot 0x400 (EmitFootDustParticle) at a recorder stub that saves the scale argument;
  system object (global 0x70039c) slot 0x1c0 at a heap code stub 'fld dword [x]; ret 8' returning a float x in [0, 1).
GetAnimFromStatus, createmat, PSVECAdd, PSVECSubtract, vscalar and DeltaTime run as original code."""
import struct
from pilot import S

BASEMOVE_VT = 0x6b75a0   # 26 slots
ANIMLIST_VT = 0x68b604


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _vec(c, n, lo, hi):
    a = c.emu.alloc(4 * n + 0x10, 4)
    for i in range(n):
        c.emu.wf32(a + 4 * i, c.rng.uniform(lo, hi))
    return a


def _recorder(c, nargs, ret):
    # heap code stub: copy the nargs stack args into a buffer, bump a call counter, 'ret 4*nargs'
    buf = c.emu.alloc(4 * nargs + 4, 4)
    code = b''
    for i in range(nargs):
        code += b'\x8b\x44\x24' + bytes([4 + 4 * i]) + b'\xa3' + struct.pack('<I', buf + 4 * i)
    code += b'\xff\x05' + struct.pack('<I', buf + 4 * nargs) + b'\xc2' + struct.pack('<H', ret)
    a = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(a, code)
    return a


def _move(c):
    r = c.rng
    obj = _rnd(c, 0x800)
    vt = c.emu.alloc(26 * 4, 4)
    for i in range(26):
        c.emu.w32(vt + 4 * i, c.emu.r32(BASEMOVE_VT + 4 * i))
    c.emu.w32(vt + 0x40, _recorder(c, 5, 0x14))
    c.emu.w32(vt + 0x48, _recorder(c, 5, 0x14))
    c.emu.w32(obj, vt)
    player = _rnd(c, 0x900)
    pvt = c.emu.alloc(0x410, 4)
    c.emu.w32(pvt + 0x400, _recorder(c, 1, 4))
    c.emu.w32(player, pvt)
    fl = r.getrandbits(32)
    if r.random() < 0.5:
        fl &= ~0xc000000
    c.emu.w32(player + 0x417, fl)
    c.emu.w32(obj + 0x36d, player)
    c.emu.w32(obj + 4, player)   # GetActiveWalk/RunDefsList read [this+4]+0x417
    for off in (0x25, 0x3d, 0x3d3, 0x3eb, 0x4ab, 0x523):   # embedded ZAnimDefsList objects
        c.emu.w32(obj + off, ANIMLIST_VT)
        c.emu.w32(obj + off + 0x14, 0)   # no REFTAB list (batch 32 note)
        c.emu.w32(obj + off + 4, _rnd(c, 0x10))   # GetAnim's default anim; GetAnimFromStatus reads its first dword
    for i in range(3):
        c.emu.wf32(obj + 0x53f + 4 * i, r.uniform(-5.0, 5.0) if r.random() < 0.8 else 0.0)
    c.emu.wf32(obj + 0x53b, r.uniform(0.0, 200.0))
    c.emu.wf32(obj + 0x18, 0.0 if r.random() < 0.5 else r.uniform(0.0, 0.1))
    sysobj = _rnd(c, 0x100)
    svt = c.emu.alloc(0x200, 4)
    val = c.emu.alloc(4, 4)
    c.emu.wf32(val, r.random())
    code = c.emu.alloc(16, 16)
    c.emu.wbytes(code, b'\xd9\x05' + struct.pack('<I', val) + b'\xc2\x08\x00')
    c.emu.w32(svt + 0x1c0, code)
    c.emu.w32(sysobj, svt)
    c.emu.wf32(sysobj + 0x48, r.uniform(0.0, 0.1))
    c.emu.w32(sysobj + 0x40, r.randint(0, 4096))
    c.emu.w32(0x70039c, sysobj)
    game = _rnd(c, 0xac0)
    c.emu.wbytes(game + 0xab8, bytes([0 if r.random() < 0.7 else 1]))
    c.emu.w32(0x7003b8, game)
    a0 = _vec(c, 3, -50.0, 50.0)
    a1 = _vec(c, 3, -50.0, 50.0)
    a2 = _vec(c, 12, -1.0, 1.0)
    a3 = _vec(c, 3, -50.0, 50.0)
    if r.random() < 0.5:   # short steps so the accumulator crosses the 50 and 150 thresholds at different rates
        for i in range(3):
            c.emu.wf32(a3 + 4 * i, c.emu.rf32(a1 + 4 * i) + r.uniform(-3.0, 3.0))
    a4 = _vec(c, 3, -5.0, 5.0)
    if r.random() < 0.4:   # slow walk: speed s = |vel + a4| * 0.125 * 480 lands in [0, 20) to reach the idle and jitter paths
        sp = r.uniform(0.0, 20.0) / 60.0
        dx, dy, dz = r.uniform(-1, 1), r.uniform(-1, 1), r.uniform(-1, 1)
        n = max((dx * dx + dy * dy + dz * dz) ** 0.5, 1e-3)
        for i, dv in enumerate((dx, dy, dz)):
            c.emu.wf32(a4 + 4 * i, -c.emu.rf32(obj + 0x53f + 4 * i) + dv / n * sp)
    c.emu.mu.ctl_flush_tb()   # stub code changes per input at reused heap addresses; drop unicorn's translated blocks
    return [obj, a0, a1, a2, a3, a4]


S(0x5e5c00, 'ZFFHeroMovementBaseMove::Move', 'thiscall', None, ret=None, gen=_move,
  note='batch45; walk root; callee stand-ins for the two vtable moves, foot dust and the system float call')

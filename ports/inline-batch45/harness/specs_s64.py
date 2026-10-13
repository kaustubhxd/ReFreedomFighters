"""specs_s64.py - inline session batch 64: ZFFActionThrow::Update. The camera helper is the batch 53 fire-aim setup
(GetFireAimPos and its chain run as exe code); a larger copy of the 0x70039c object adds the tick count (+0x40) and the
level's ray tester (+0x1aa3 -> +0x1c). The ray tester's slot 0x30 is a stub that logs both calls (from, direction,
fraction in, the five value arguments), writes a per-call fraction and returns a per-call hit flag. The vector helpers,
ProgressValue and the camera-helper getter run as exe code; hero and item calls are heap recorder stubs."""
import math
import struct
from pilot import S
import specs_s53 as k53
import specs_s60 as k60

_rnd, _stub, _obj = k53._rnd, k53._stub, k53._obj
_seq, _fv = k60._seq, k60._fv
XYZ = [(0, 'd'), (4, 'd'), (8, 'd')]


def _raystub(c, calls):
    """thiscall (frac*, a, from*, dir*, b, c, d, e), ret 0x20. calls = [(frac, hit)] for call 0 and 1."""
    tab = c.emu.alloc(16, 4)
    c.emu.wbytes(tab, b''.join(struct.pack('<fI', f, h) for f, h in calls))
    cnt = c.emu.alloc(4, 4)
    log = c.emu.alloc(2 * 64, 4)
    P = lambda v: struct.pack('<I', v)
    code = b'\xa1' + P(cnt) + b'\x83\xe0\x01\xc1\xe0\x06\x05' + P(log)
    code += b'\x8b\x4c\x24\x04\x8b\x11\x89\x10'          # fraction in
    code += b'\x8b\x54\x24\x08\x89\x50\x04'              # a
    for argoff, dst in ((0x0c, 0x08), (0x10, 0x14)):     # from, dir
        code += b'\x8b\x4c\x24' + bytes([argoff])
        for j in range(3):
            code += b'\x8b\x51' + bytes([4 * j]) + b'\x89\x50' + bytes([dst + 4 * j])
    for i in range(4):                                   # b, c, d, e
        code += b'\x8b\x54\x24' + bytes([0x14 + 4 * i]) + b'\x89\x50' + bytes([0x20 + 4 * i])
    code += b'\x8b\x0d' + P(cnt) + b'\x83\xe1\x01\x8b\x14\xcd' + P(tab)
    code += b'\x8b\x44\x24\x04\x89\x10\x8b\x04\xcd' + P(tab + 4)
    code += b'\xff\x05' + P(cnt) + b'\xc2\x20\x00'
    a = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(a, code)
    return a


def _bump(c, addr, stub):
    code = b'\xff\x05' + struct.pack('<I', addr) + b'\xb8' + struct.pack('<I', stub) + b'\xff\xe0'
    a = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(a, code)
    return a


def _anim(c, frames):
    r = c.rng
    a = _rnd(c, 0x90)
    start = r.choice((0, r.randint(0, 1000), r.getrandbits(32)))
    c.emu.w32(a + 0x60, start)
    c.emu.w32(a + 0x64, (start + frames) & 0xffffffff)
    c.emu.w32(a + 0x5c, r.choice((r.randint(-100, 3000), 0, 1)) & 0xffffffff)
    c.emu.w32(a + 0x6c, r.choice((r.randint(1, 3000), 0, 30, -7)) & 0xffffffff)
    return a


def _secs(ticks):
    return struct.unpack('<f', struct.pack('<f', ticks / 1024.0))[0]


def _upd(c):
    r = c.rng
    cam = k53._fireaim_cam(c)
    old = c.emu.r32(0x70039c)
    sysobj = _rnd(c, 0x1ab0)
    c.emu.wbytes(sysobj, bytes(c.emu.mu.mem_read(old, 0xa0)))
    now = r.choice((r.randint(0, 1 << 22), r.randint(1 << 22, 1 << 30), r.getrandbits(32) & 0x7fffffff))
    c.emu.w32(sysobj + 0x40, now)
    rt = _rnd(c, 0x40)
    calls = [(r.choice((1.0, 0.0, 0.5, r.uniform(0.0, 1.0), r.uniform(-1, 2))), r.getrandbits(32) & (0xffffff00 if r.random() < 0.5 else 0xffffffff))
             for _ in range(2)]
    rayo = _obj(c, 0x20, {0x30: _raystub(c, calls)})
    c.emu.w32(rt + 0x1c, rayo)
    c.emu.w32(sysobj + 0x1aa3, rt)
    c.emu.w32(0x70039c, sysobj)
    # 2026-10-12 (docs/41): the assert hook is always set. With no hook and no camera helper both builds stop on int3,
    # a faulting case, which the strict rule (faulting_cases == 0) does not allow; the hook-call path is still tested.
    c.emu.w32(0x7003b0, _stub(c, 0))
    item = _obj(c, 0x120, {0x32c: _stub(c, 1, skip=(0,), copy=(0, XYZ)), 0x2d0: _seq(c, 2, [0]),
                           0x35c: _stub(c, 0, ret=r.choice((0, 0, 1, r.getrandbits(32))))})
    hero = _obj(c, 0x900, {
        0x100: _stub(c, 1, ret=cam if r.random() < 0.9 else 0),
        0x244: _bump(c, sysobj + 0x40, _stub(c, 5)) if r.random() < 0.5 else _stub(c, 5),
        0x268: _stub(c, 2),
        0x50c: _stub(c, 0, ret=item),
        0x84: _stub(c, 1, skip=(0,), copy=(0, XYZ), adds=((0, _fv(c, [r.uniform(-3000, 3000) for _ in range(3)]), 3),)),
        0x88: _stub(c, 1, skip=(0,), copy=(0, XYZ), adds=((0, _fv(c, [r.uniform(-60, 60) for _ in range(3)]), 3),)),
        0x560: _stub(c, 1, ret=r.choice((0, 0, 1, (-1) & 0xffffffff, r.getrandbits(32)))),
        0x54c: _stub(c, 2)})
    c.emu.w32(hero + 0x85a, cam if r.random() < 0.8 else 0)
    c.emu.w32(hero + 0x852, _rnd(c, 0x2300))
    c.emu.wbytes(hero + 0x669, bytes([r.choice((0, 0, 1, r.randint(0, 255)))]))
    self = _rnd(c, 0x30)
    c.emu.w32(self + 8, hero)
    edge = r.random() < 0.25
    c.emu.w32(self + 0xc, _anim(c, 25 if edge else r.choice((r.randint(1, 60), 0, 1, r.getrandbits(32)))))
    c.emu.w32(self + 0x10, _anim(c, 25 if edge else r.choice((r.randint(1, 60), 0, r.getrandbits(32)))))
    # times: t0 at or before now most of the time, t2 around the 9/25 s release point
    t0 = now - (1024 if edge and r.random() < 0.7 else r.choice((0, 1, r.randint(0, 3000), r.randint(-50, 0), r.getrandbits(20))))
    c.emu.wf32(self + 0x14, r.choice((_secs(t0), _secs(t0), math.nan, -1.0, 1e10)))
    c.emu.wf32(self + 0x18, _secs(now - r.randint(-200, 4000)))
    t2 = now - (1024 if edge and r.random() < 0.7 else r.choice((368, 369, 370, 0, r.randint(0, 2000), r.randint(300, 450))))
    c.emu.wf32(self + 0x1c, r.choice((_secs(t2), _secs(t2), _secs(t2), math.nan)))
    c.emu.wbytes(self + 0x20, bytes([r.choice((0, 0, 0, 1, r.randint(0, 255))), r.choice((0, 1, r.randint(0, 255)))]))
    c.emu.mu.ctl_flush_tb()
    return [self]


S(0x5e0620, 'ZFFActionThrow::Update', 'thiscall', None, ret='al', gen=_upd,
  note='batch64; throw tree; GetFireAimPos chain and the vector helpers as exe code')

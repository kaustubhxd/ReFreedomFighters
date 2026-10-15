"""specs_s400.py - batch 400: ZIKLNKOBJ::ClassFrameUpdate, ZPlayer::ClassFrameUpdate, ZCamHelper::ControlBody.
Every vtable call and every hooked exe callee is a Python stub that logs (name, this, args) in order. The profiler
begin/end functions (batch 48) run as exe code against a stub engine object."""
from pilot import S
import fu_kit as K


def _ik(c):
    r = c.rng
    K.hooks(c, {0x461c40: ('ZLNKOBJ::ClassFrameUpdate', 0)})
    self = K.obj(c, 0x700, {0x410: K.fn(c, 'UpdateTargets', 0, ret=r.getrandbits(32))}, 'player')
    return [self]


def _player(c):
    r = c.rng
    K.hooks(c, {0x461c40: ('ZLNKOBJ::ClassFrameUpdate', 0), 0x482b80: ('ZPlayer::DebugControl', 0)})
    K.sysobj(c)
    geom = K.rnd(c, 0x40)
    if r.random() < 0.5:
        c.emu.w32(geom + 0x3c, c.emu.r32(geom + 0x3c) & ~0x800)
    g = K.rnd(c, 0x10)
    c.emu.w32(g + 8, geom)
    mats = [[r.uniform(-2, 2) for _ in range(9)], [r.uniform(-500, 500) for _ in range(3)]]
    nmats = [[r.uniform(-2, 2) for _ in range(9)], [r.uniform(-500, 500) for _ in range(3)]]

    def center(e, a):
        K.wfloats(e, a[0], mats[0])
        K.wfloats(e, a[1], mats[1])

    def move(e, a):
        K.wfloats(e, a[2], nmats[0])
        K.wfloats(e, a[3], nmats[1])

    slots = {
        0x20: K.fn(c, 'slot20', 0, ret=g),
        0x410: K.fn(c, 'UpdateTargets', 0),
        0x5ec: K.fn(c, 'UpdatePoolGeoms', 0, ret=r.getrandbits(32)),
        0x604: K.fn(c, 'slot604', 0),
        0x348: K.fn(c, 'UpdateAnimationsAndGroundLink', 0),
        0x59c: K.fn(c, 'GetCenterMatPos', 2, body=center),
        0x61c: K.fn(c, 'MovementControl', 4, body=move, sizes={0: 36, 1: 12}),
        0x600: K.fn(c, 'CalcBonesFromMotion', 4, sizes={0: 36, 1: 12, 2: 36, 3: 12}),
        0x5f0: K.fn(c, 'SetGroupPos', 2, sizes={0: 36, 1: 12}),
    }
    self = K.obj(c, 0x700, slots, 'player')
    K.setbyte(c, self + 0x5fe, 0.75)
    K.setbyte(c, self + 0x412, 0.3)
    return [self]


def _body(c):
    r = c.rng
    tbl = {a: (n, 0) for a, n in [(0x5ceb30, 'ControlMouse'), (0x5ceb70, 'ControlOni'), (0x5cdab0, 'ControlA'),
                                   (0x5cff20, 'cam5cff20'), (0x5d0080, 'cam5d0080'), (0x5cecd0, 'DoMoveFocus')]}
    tbl[0x5cf420] = ('aimOrigin', 1)
    K.hooks(c, tbl)
    o = K.obj(c, 0x40, {0x80: K.fn(c, 'o.slot80', 2)}, 'o')
    rm = K.obj(c, 0x100, {0x58: K.fn(c, 'rm.handle', 1, ret=o)}, 'rm')
    sysobj = K.rnd(c, 0x100)
    c.emu.w32(sysobj + 0x9b, rm)
    c.emu.w32(0x70039c, sysobj)
    hero_a = K.obj(c, 0x700, {0x80: K.fn(c, 'hero.slot80', 2), 0x438: K.fn(c, 'hero.slot438', 0, ret=K.bool8(c, 0.6))},
                   'hero')
    hero_b = K.obj(c, 0x700, {0x438: K.fn(c, 'hero2.slot438', 0, ret=K.bool8(c, 0.6))}, 'hero2')
    cam = K.obj(c, 0xf00, {0x84: K.fn(c, 'cam.slot84', 0,
                                        body=lambda e, a: e.w32(cam_[0] + 0x44, hero_b) if swap else None)}, 'cam')
    cam_ = [cam]
    swap = r.random() < 0.2   # slot 0x84 replaces the hero pointer: the middle test must re-read +0x44
    c.emu.w32(cam + 0x44, hero_a)
    K.setbyte(c, cam + 0xdd8, 0.6)
    c.emu.w32(cam + 0xe1c, r.choice([0, 1, 2, 3, 4, r.getrandbits(32)]))
    return [cam]


S(0x465fb0, 'ZIKLNKOBJ::ClassFrameUpdate', 'thiscall', None, ret=None, gen=_ik, note='batch400')
S(0x482370, 'ZPlayer::ClassFrameUpdate', 'thiscall', None, ret=None, gen=_player, note='batch400; profiler as exe code')
S(0x5cdb70, 'ZCamHelper::ControlBody', 'thiscall', None, ret=None, gen=_body, note='batch400')

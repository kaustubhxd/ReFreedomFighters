"""specs_s504.py - weapons batch 504: ZTARGET and ZLNKWHANDS aim helpers."""
from pilot import S
from pe_emu import F
from wkit import rnd, stub, obj, b, sysobj, fedge, patch_jmp, vec


def _tgt(c, base=None, off=0):
    """Fill a ZTARGET at base+off (random bytes already there) with plausible fields."""
    r = c.rng
    t = base + off
    c.emu.w8(t, 0 if r.random() < 0.4 else r.randint(1, 255))
    if r.random() < 0.3:
        c.emu.w32(t + 0x25, 0x7fffffff)
    for o in (0x25, 0x29, 0x2d):
        if c.emu.r32(t + o) != 0x7fffffff:
            c.emu.wf32(t + o, fedge(c))
    c.emu.w32(t + 0x39, 0 if r.random() < 0.3 else r.getrandbits(32))
    return t


def _ticks(c):
    r = c.rng
    so = c.emu.r32(0x70039c)
    now = r.choice((0, 1024, r.randint(0, 1 << 22), r.randint(0, 1 << 22), r.getrandbits(32)))
    c.emu.w32(so + 0x40, now)
    return now


def _t0(c):
    o = rnd(c, 0x80)
    _tgt(c, o)
    return [o]


def _t_b(c):
    return _t0(c) + [b(c, 0.5)]


def _t_rem(c):
    o = rnd(c, 0x80)
    c.emu.wf32(o + 0x35, fedge(c))
    return [o]


def _t_out(c):
    return _t0(c) + [rnd(c, 0x20)]


def _t_cb(c):
    r = c.rng
    return _t0(c) + [r.getrandbits(32), r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]


def _t_mpg(c):
    r = c.rng
    o = rnd(c, 0x80)
    m = 0 if r.random() < 0.3 else vec(c, 9, -5, 5)
    p = 0 if r.random() < 0.3 else vec(c, 3, -100, 100)
    return [o, m, p, r.getrandbits(32)]


def _t_upd(c):
    patch_jmp(c, 0x465930, stub(c, 1, rec_ecx=True))
    return _t0(c) + [c.rng.getrandbits(32)]


def _t_cbr(c):
    r = c.rng
    o = rnd(c, 0x80)
    objp = rnd(c, 0x100)
    n = r.choice((0, 1, 1, 2))
    if n == 0:
        c.emu.w32(o + 0x3d, 0)
    else:
        # the callback re-arms the target with a second callback (n == 2), which must also run once
        cb2 = stub(c, 0, rec_ecx=True)
        if n == 2:
            st = c.emu.alloc(0x40, 16)
            code = (b'\xb8' + (o + 0x3d).to_bytes(4, 'little') +            # mov eax, t+0x3d
                    b'\xc7\x00' + cb2.to_bytes(4, 'little') +                 # mov [eax], cb2
                    b'\xc7\x40\x04' + (8).to_bytes(4, 'little') +             # mov [eax+4], 8
                    b'\x89\x0d' + (st + 0x30).to_bytes(4, 'little') + b'\xc3')  # mov [st+0x30], ecx; ret
            c.emu.wbytes(st, code)
            fn = st
        else:
            fn = cb2
        c.emu.w32(o + 0x3d, fn)
        c.emu.w32(o + 0x41, r.choice((0, 4, 0x10)))
    return [o, objp]


def _t_settime(c):
    r = c.rng
    sysobj(c, {})
    now = _ticks(c)
    o = rnd(c, 0x80)
    x = r.random()
    if x < 0.6:   # a start stamp around now (+ or -), duration around the elapsed time
        el = r.choice((0, 1, 100, 1024, r.randint(0, 4000)))
        st = (now - el) / 1024.0 if now < (1 << 23) else r.uniform(0, 1000)
        c.emu.wf32(o + 0x35, st if r.random() < 0.5 else -st)
        c.emu.wf32(o + 0x31, r.choice((0.0, el / 1024.0, r.uniform(0, 4), float('nan'))))
    else:
        c.emu.wf32(o + 0x35, fedge(c))
        c.emu.wf32(o + 0x31, fedge(c))
    return [o, F(r.choice((0.0, 0.25, 1.0, r.uniform(0, 3), fedge(c)))), b(c, 0.5)]


def _hands(c, slots=None):
    o = obj(c, 0x500, slots or {})
    _tgt(c, o, 0x26a)
    return o


def _h_setaim(c):
    r = c.rng
    o = _hands(c, {0x4ac: stub(c, 7)})
    return [o, vec(c, 3, -10, 10), F(r.uniform(0, 2)), r.getrandbits(32), r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]


def _h0(c):
    return [_hands(c)]


def _h_out(c):
    return [_hands(c), rnd(c, 0x10)]


def _h_aimpos(c):
    r = c.rng
    sysobj(c, {0x58: stub(c, 1, ret=0 if r.random() < 0.4 else r.getrandbits(32))})
    o = _hands(c, {0x84: stub(c, 1)})
    return [o, rnd(c, 0x10)]


def _h_dis(c):
    return [_hands(c, {0x4b4: stub(c, 5)})]


def _h_b(c):
    return [_hands(c), b(c, 0.5)]


def _h_fsn(c):
    o = _hands(c)
    c.emu.wf32(o + 0x1e2, c.rng.choice((0.0, 0.3, 0.29999998, 0.5, 1.0, float('nan'), c.rng.uniform(-1, 2))))
    return [o]


def _hold(c):
    r = c.rng
    o = rnd(c, 0x800)
    c.emu.w8(o + 0x669, r.choice((0, 1, 2)))
    return [o, r.choice((0, 1, 2, 0x100))]


S(0x466cd0, 'ZTARGET IsEnabled (guess)', 'thiscall', None, ret='al', gen=_t0)
S(0x466600, 'ZTARGET::Enable', 'thiscall', None, ret='al', gen=_t_b)
S(0x4666d0, 'ZTARGET::Geom', 'thiscall', None, ret='eax', gen=_t0)
S(0x4673c0, 'ZTARGET::Pos', 'thiscall', None, ret='eax', gen=_t0)
S(0x467700, 'ZTARGET::Removing', 'thiscall', None, ret='al', gen=_t_rem)
S(0x4669c0, 'ZTARGET::GetPos', 'thiscall', None, ret='al', gen=_t_out)
S(0x4678e0, 'ZTARGET::SetCallBack', 'thiscall', None, ret=None, gen=_t_cb)
S(0x4667e0, 'ZTARGET::GetCallBack', 'thiscall', None, ret='eax', gen=_t_out)
S(0x466220, 'ZTARGET::Clear', 'thiscall', None, ret=None, gen=_t0)
S(0x465650, 'ZTARGET::ZTARGET', 'thiscall', None, ret='eax', gen=_t0)
S(0x467aa0, 'ZTARGET::SetMatPosGeom', 'thiscall', None, ret=None, gen=_t_mpg)
S(0x467cd0, 'ZTARGET::Update', 'thiscall', None, ret=None, gen=_t_upd)
S(0x4658d0, 'ZTARGET::CallBackAndRemove', 'thiscall', None, ret=None, gen=_t_cbr)
S(0x467b00, 'ZTARGET::SetTime', 'thiscall', None, ret=None, gen=_t_settime)
S(0x475710, 'ZLNKWHANDS::SetAimTarget(pos)', 'thiscall', None, ret=None, gen=_h_setaim)
S(0x473fb0, 'ZLNKWHANDS::GetAimTarget()', 'thiscall', None, ret='eax', gen=_h0)
S(0x473fc0, 'ZLNKWHANDS::GetAimTarget(u32*)', 'thiscall', None, ret='al', gen=_h_out)
S(0x473f20, 'ZLNKWHANDS::GetAimTarget(float*)', 'thiscall', None, ret='al', gen=_h_aimpos)
S(0x4746d0, 'ZLNKWHANDS::IsAiming', 'thiscall', None, ret='al', gen=_h0)
S(0x473a10, 'ZLNKWHANDS::DisableAim', 'thiscall', None, ret=None, gen=_h_dis)
S(0x473b40, 'ZLNKWHANDS::EnableAim', 'thiscall', None, ret=None, gen=_h0)
S(0x473e30, 'ZLNKWHANDS::FreezeAimTarget', 'thiscall', None, ret=None, gen=_h0)
S(0x4754d0, 'ZLNKWHANDS::SetAimInPosition', 'thiscall', None, ret=None, gen=_h_b)
S(0x473b50, 'ZLNKWHANDS::FireShotNotify', 'thiscall', None, ret=None, gen=_h_fsn)
S(0x594f10, 'ZFFHERO::SetHoldFire', 'thiscall', None, ret=None, gen=_hold)

"""specs_c1025.py - camera batch 1025: hero aim helpers."""
from pilot import S
from camgen import rnd, fbits, Log, handler, handler2, sys_with_mgr

S(0x46efe0, 'ZItemTemplateWeapon::HasSniperMode', 'thiscall', ret='al', gen=lambda c: [rnd(c, 0x100)])


def _cam(c):
    r = c.rng
    log = Log(c)
    h = rnd(c, 0x870)
    c.emu.w32(h + 0x85e, r.choice([0, 0, r.getrandbits(32)]))
    g = c.emu.fake_object('camgeom', 0x10, slots={0x100: handler(log, 0x100, 1, eax=r.getrandbits(32))}) if r.random() < 0.8 else 0
    c.emu.w32(h + 0x84e, g)
    return [h]


S(0x591ae0, 'ZFFHERO::GetFFCamPtr', 'thiscall', ret='eax', gen=_cam)
S(0x593ae0, 'ZFFHERO::OnlyVerticalAim', 'thiscall', ret='al', gen=lambda c: [rnd(c, 0x830)])
S(0x594fa0, 'ZFFHERO::SetOnlyVerticalAim', 'thiscall', ret='al', gen=lambda c: [rnd(c, 0x830), c.rng.getrandbits(32)])


def _item(c, log, t):
    tmpl = c.emu.fake_object('tmpl', 0x10, slots={0x330: handler(log, 0x330, 0, eax=t)})
    return c.emu.fake_object('item', 0x120, slots={0x350: handler(log, 0x350, 0, eax=tmpl),
                                                  0x34c: handler2(c, log, 0x34c, 'F')})


def _hero(c, log, extra=None):
    r = c.rng
    types = list(range(14)) + [r.getrandbits(32)]
    w = _item(c, log, r.choice(types)) if r.random() < 0.85 else 0
    l = _item(c, log, r.choice(types[:3])) if r.random() < 0.6 else 0
    slots = {0x50c: handler(log, 0x50c, 0, eax=w), 0x508: handler(log, 0x508, 0, eax=l),
             0x49c: handler(log, 0x49c, 0, eax=r.choice([0, 1]))}
    slots.update(extra or {})
    h = c.emu.fake_object('hero', 0x870, slots=slots)
    c.emu.wbytes(h + 4, bytes(r.getrandbits(8) for _ in range(0x86c)))
    return h


def _aa(c):
    return [_hero(c, Log(c))]


S(0x473e50, 'ZLNKWHANDS::GetAimAnim', 'thiscall', ret='eax', gen=_aa)


def _faa(c):
    r = c.rng
    log = Log(c)
    c.emu.hook(0x473e50, handler(log, 0x473e50, 0, eax=r.getrandbits(32)))
    h = _hero(c, log)
    c.emu.w32(h + 0x417, r.choice([0, 0x40000, 0x2000000, r.getrandbits(32)]))
    return [h]


S(0x591880, 'ZFFHERO::GetAimAnim', 'thiscall', ret='eax', gen=_faa)


def _cb(c):
    r = c.rng
    log = Log(c)
    c.emu.hook(0x4dc630, handler(log, 0x4dc630, 2, eax=r.getrandbits(32)))
    c.emu.hook(0x4816e0, handler(log, 0x4816e0, 0, eax=r.getrandbits(32)))
    h = _hero(c, log, {0x84: handler2(c, log, 0x84, 'v'), 0x100: handler(log, 0x100, 1, eax=0)})
    helper = rnd(c, 0xd40)
    c.emu.w8(helper + 0xb45, r.choice([0, 1]))
    c.emu.w32(h + 0x85a, helper)
    c.emu.w32(h + 8, rnd(c, 0x40))

    def ray(e, res):
        q, d = e.arg32(2), e.arg32(3)
        log.put(0x30, e.r32(e.arg32(0)), e.arg32(1), *[e.r32(q + 4 * i) for i in range(3)],
                *[e.r32(d + 4 * i) for i in range(3)], *[e.arg32(i) for i in range(4, 8)])
        hit = r.choice([0, 1, 0x100])
        if hit & 0xff:
            for i in range(3):
                e.w32(q + 4 * i, fbits(c))
        e.ret(eax=hit, argbytes=32)
    holder = rnd(c, 0x20)
    c.emu.w32(holder + 0x1c, c.emu.fake_object('coll', 0x40, slots={0x30: ray}))
    s = sys_with_mgr(c, 0x1b00)
    c.emu.w32(s + 0x1aa3, holder)
    return [h]


S(0x58c2b0, 'ZFFHERO::CallBackAimInPosition', 'thiscall', gen=_cb)

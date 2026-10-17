"""specs_s405.py - batch 405: ZLNKOBJ::UpdateAnimationsAndGroundLink."""
import math
from pilot import S
import fu_kit as K


def _upd(c):
    r = c.rng
    e = c.emu
    K.install_cifmod(c)
    so = K.rnd(c, 0x50)
    now = r.randint(0, 1 << 22)
    e.w32(so + 0x40, now)
    e.w32(0x70039c, so)
    nodes = []
    for i in range(r.choice([0, 1, 1, 2, 3, 5])):
        node = K.rnd(c, 0x80)
        b = node + 4
        data = K.rnd(c, 0x80)
        rate = r.choice([30, 25, 15, 1, 0, r.randint(-5, 100)])
        e.w32(data + 0x6c, rate & 0xffffffff)
        e.w32(b + 0x70, data)
        speed = r.choice([1.0, 0.5, 2.0, c.fv(-2, 3)])
        e.wf32(b + 0x28, speed)
        since = r.randint(-100, 20000)
        e.wf32(b + 0x1c, (now - since) / 1024.0 if r.random() < 0.9 else c.fv(-1e4, 1e4))
        e.w32(b + 0x44, r.choice([0, 0, 1, 3, 0xffffffff, 0xfffffffe]))
        t = rate * speed * since / 1024.0 if math.isfinite(speed) and abs(speed) < 1e6 else 0.0
        ln = r.choice([max(t, 0) + r.uniform(-2, 2), r.uniform(0, 100), float(int(t)) if abs(t) < 1e6 else 1.0])
        e.wf32(b + 0x18, ln)
        period = r.choice([0, 0, 1, 2, 5, 10, -3])
        e.w32(b + 0xc, period & 0xffffffff)
        nodes.append((node, t, period))
    # event counter: often the value the next event is due at
    cnt = r.randint(0, 50)
    if nodes and r.random() < 0.6:
        _, t, p = r.choice(nodes)
        if p and abs(t) < 1e8:
            cnt = int(t) // p if p > 0 else -(int(t) // -p)
            cnt = int(int(t) / p)
    state = {'i': -1}

    def nxt(ee, a):
        state['i'] += 1
        return nodes[state['i']][0] if state['i'] < len(nodes) else 0
    upd_mod = r.random() < 0.2

    def ucb(ee, a):
        if upd_mod:   # the callback moves the time: the end and event tests must re-read it
            ee.wf32(ee.reg('ecx') + 4, 12.5)
    K.hooks(c, {0x462510: ('ZBoneAnim::Destroy', 1), 0x465330: ('ZBoneAnim::UpdateCallBacks', 1, 0, ucb),
                0x463da0: ('lnk.463da0', 2)})
    lst = K.obj(c, 0x80, {0x4c: K.fn(c, 'list.begin', 1), 0x64: K.fn(c, 'list.next', 1, ret=nxt),
                          0x44: K.fn(c, 'list.remove', 1)}, 'list')
    link = K.obj(c, 0x80, {0x5c: K.fn(c, 'link.ground', 3, ret=K.bool8(c, 0.5))}, 'link')
    self = K.obj(c, 0x200, {0x270: K.fn(c, 'slot270', 2), 0x268: K.fn(c, 'slot268', 2), 0x26c: K.fn(c, 'slot26c', 0),
                            0x340: K.fn(c, 'slot340', 2)}, 'lnk')
    e.w32(self + 0x18, lst if r.random() < 0.9 else 0)
    e.w32(self + 0x6c, link)
    e.w32(self + 0x122, cnt & 0xffffffff)
    ntr = r.choice([0, 1, 2, 3])
    tab = K.rnd(c, 0x18 * max(ntr, 1))
    for i in range(max(ntr, 1)):
        x = r.random()
        if x < 0.1 and i == 0:
            ba = 0
        elif x < 0.5 and nodes:
            ba = r.choice(nodes)[0] + 4
        else:
            ba = K.rnd(c, 0x80)
            ln = r.uniform(0, 50)
            e.wf32(ba + 0x18, ln)
            e.wf32(ba + 4, ln + r.choice([0.0, 1.0, -1.0, 7.25, 30.0]))
            e.w32(ba + 0xc, r.choice([0, 1, 4, 24, 30, int(ln)]) & 0xffffffff)
        e.w32(tab + 0x18 * i + 0x14, ba)
    e.w32(self + 0x1c, tab)
    e.w32(self + 0x20, ntr)
    return [self]


S(0x4650c0, 'ZLNKOBJ::UpdateAnimationsAndGroundLink', 'thiscall', None, ret='al', gen=_upd,
  note='batch405; _CIfmod as fprem code; mreset as exe code')

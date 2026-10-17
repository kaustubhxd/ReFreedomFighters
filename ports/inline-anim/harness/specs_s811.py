"""specs_s811.py - animation layer thread, batch 811: ZBoneAnim Create/AddCallBack/Destroy/UpdateCallBacks.
The callback list (LINKSORTREFTAB) is a Python sorted list behind a fake vtable; iterator buffers are stack
locals, so the iterator position is kept in Python and the buffer address is not logged."""
import bisect
from pilot import S, F, f32
from anim_common import only_hooks, logged_fn, rnd, vt_object, vslot


class CbList:
    def __init__(self, c, ba):
        self.c, self.ba, self.items, self.pos, self.cur = c, ba, [], 0, None
        e = c.emu
        slots = {0x14: self.count, 0x4c: self.begin, 0x64: self.next, 0x9c: self.key, 0x44: self.remove,
                 0xa0: self.reinsert, 0x98: self.add, 0: self.dtor}
        self.obj = e.fake_object('cblist', 0x20, nslots=0x2a, slots=slots)

    def _ins(self, key, node):
        keys = [k for k, _ in self.items]
        self.items.insert(bisect.bisect_right(keys, key), (key, node))

    def node(self, key, flags, fn):
        e = self.c.emu
        n = e.alloc(0x10, 4)
        e.w32(n, flags)
        e.w32(n + 4, 0 if self.c.rng.random() < 0.1 else 1)
        e.w32(n + 8, fn)
        self._ins(f32(key), n)
        return n

    def count(self, e, r):
        e.calllog.append(('list.count', len(self.items)))
        e.ret(eax=len(self.items), argbytes=0)

    def begin(self, e, r):
        self.pos, self.cur = 0, None
        e.calllog.append(('list.begin',))
        e.ret(eax=0, argbytes=4)

    def next(self, e, r):
        if self.pos < len(self.items):
            self.cur = self.items[self.pos]
            self.pos += 1
            n = self.cur[1]
        else:
            n = 0
        e.calllog.append(('list.next', n))
        e.ret(eax=n, argbytes=4)

    def key(self, e, r):
        n = e.arg32(0)
        k = next((k for k, m in self.items if m == n), 1e9)
        e.calllog.append(('list.key', n))
        e.ret(st0=k, argbytes=4)

    def remove(self, e, r):
        e.calllog.append(('list.remove', self.cur[1] if self.cur else None))
        if self.cur in self.items:
            self.items.remove(self.cur)
            self.pos -= 1
        e.ret(eax=0, argbytes=4)

    def reinsert(self, e, r):
        n, k = e.arg32(0), e.argf(1)
        e.calllog.append(('list.reinsert', n, e.arg32(1)))
        self._ins(k, n)
        e.ret(eax=0, argbytes=8)

    def add(self, e, r):
        a, k, b = e.arg32(0), e.argf(1), e.arg32(2)
        e.calllog.append(('list.add', a, e.arg32(1), b))
        n = e.alloc(0x10, 4)
        self._ins(k, n)
        e.ret(eax=n + 4, argbytes=12)

    def dtor(self, e, r):
        e.calllog.append(('list.delete', e.arg32(0)))
        e.ret(eax=0, argbytes=4)


def _create(c):
    only_hooks(c, {})
    e, r = c.emu, c.rng
    sc = vt_object(c, 0x20, {0x18: vslot('scene.NewAnimId', 0, ret=r.getrandbits(32))})
    g = rnd(c, 0xa0)
    e.w32(g + 0x9b, sc)
    e.w32(0x70039c, g)
    name = c.emu.alloc(0x40, 4)
    s = bytes(r.choice(b'abcdefgh_XYZ0123') for _ in range(r.randint(0, 30)))
    e.wbytes(name, s + b'\0' + bytes(r.getrandbits(8) for _ in range(8)))
    return [rnd(c, 0x80), r.getrandbits(32), name]


def _addcb(c):
    e, r = c.emu, c.rng
    ba = rnd(c, 0x80)
    lst = CbList(c, ba)

    def new(e, res):
        e.calllog.append(('new', e.arg32(0)))
        e.ret(eax=e.alloc(e.arg32(0), 8), argbytes=0)

    def ctor(e, res):
        p = e.reg('ecx')
        e.calllog.append(('LINKSORTREFTAB', p, e.arg32(0), e.arg32(1)))
        e.w32(p, e.r32(lst.obj))
        e.ret(eax=p, argbytes=8)
    only_hooks(c, {0x41e290: new, 0x4ccad0: ctor})
    e.w32(ba + 0x6c, 0 if r.random() < 0.4 else lst.obj)
    return [ba, F(c.fv(0, 100)), r.getrandbits(32), r.getrandbits(32)]


def _cb_env(c, ba, lst, hook_ok=True):
    e, r = c.emu, c.rng
    r2 = __import__('random').Random(r.getrandbits(32))

    def cb(e, res):
        a = (e.reg('ecx'), e.arg32(0), e.arg32(1), e.arg32(2), e.arg32(3))
        e.calllog.append(('callback',) + a)
        e.ret(eax=r2.choice([1, 1, 1, 0x100, 0]) & 0xff | 0xabcd00, argbytes=16)
    fns = [e.stub_fn('cb%d' % i, cb) for i in range(3)]
    for i in range(r.randint(0, 6)):
        lst.node(r.choice([r.uniform(0, 50), float(r.randint(0, 50))]), r.getrandbits(32), r.choice(fns))
    if hook_ok:
        e.w32(0x7003b0, e.stub_fn('assert', lambda e, res: (e.calllog.append(('assert',)), e.ret())))
    else:
        e.w32(0x7003b0, 0)


def _destroy(c):
    only_hooks(c, {})
    e, r = c.emu, c.rng
    ba = rnd(c, 0x80)
    lst = CbList(c, ba)
    _cb_env(c, ba, lst)
    e.w32(ba + 0x6c, 0 if r.random() < 0.15 else lst.obj)
    return [ba, r.choice([0, 1, 0x100])]


def _update(c):
    only_hooks(c, {})
    e, r = c.emu, c.rng
    ba = rnd(c, 0x80)
    lst = CbList(c, ba)
    _cb_env(c, ba, lst)
    e.w32(ba + 0x6c, 0 if r.random() < 0.1 else lst.obj)
    e.w32(ba + 0xc, r.randint(0, 100))
    now = r.choice([r.uniform(0, 60), float(r.randint(0, 50))])
    e.wf32(ba + 0x24, now if r.random() < 0.1 else c.fv(0, 60))
    return [ba, F(now)]


S(0x462460, 'ZBoneAnim::Create', 'thiscall', None, gen=_create, note='batch811')
S(0x4614d0, 'ZBoneAnim::AddCallBack', 'thiscall', None, gen=_addcb, note='batch811')
S(0x462510, 'ZBoneAnim::Destroy', 'thiscall', None, gen=_destroy, note='batch811')
S(0x465330, 'ZBoneAnim::UpdateCallBacks', 'thiscall', None, gen=_update, note='batch811')

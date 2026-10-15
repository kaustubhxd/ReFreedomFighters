"""specs_s811.py - animation layer thread, batch 811: ZBoneAnim Create/AddCallBack/Destroy/UpdateCallBacks.
The callback list (LINKSORTREFTAB) is a Python sorted list behind a fake vtable; iterator buffers are stack
locals, so the iterator position is kept in Python and the buffer address is not logged."""
import bisect
from pilot import S, F, f32
from recruits_util import clear_hooks,rnd
def only_hooks(c,_): clear_hooks(c)


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


def _update(c):
    only_hooks(c, {})
    e, r = c.emu, c.rng
    ba = rnd(c, 0x80)
    lst = CbList(c, ba)
    _cb_env(c, ba, lst)
    e.w32(ba + 0x6c, 0 if r.random() < 0.1 else lst.obj)
    e.w32(ba + 0xc, r.randint(1, 100))
    now = r.choice([r.uniform(0, 60), float(r.randint(0, 50))])
    e.wf32(ba + 0x24, now if r.random() < 0.1 else r.uniform(0,60))
    return [ba, F(now)]



S(0x465330,"ZBoneAnim UpdateCallBacks","thiscall",None,ret=None,gen=_update)
